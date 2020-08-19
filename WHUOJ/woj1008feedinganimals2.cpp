//1.1
// m,n 1-100,直接开就完事了
// 一开始想做DFS，每次选一列中的一个，然后往下，复杂度爆了
//换贪心和网络流
//贪心法。每个人权重=1.0*love[i][j]/maxn，也就是能喂的动物越少，权重越大，越优先安排他喂
//贪心有反例
//是网络流题，二分匹配

#include <iostream>
#include<vector>
#include<cstdio>
#include<stack>
using namespace std;
int person,animals,maxn;
int love[105][105];
int cnt[105];   //根据上限每个人还能喂几个    如果每个人的上限数量不同，表示每个人的数量然后计算权重就行
int summ[105]; //每个人本来能喂养的综合
bool used[105][105];
double capacity[105][105]; //每个动物占某人可喂养的权重

//复杂度 100^100 。因为这个剪枝不了，就是说如果上一层采取不同的人喂养，可能这一层原来不行的又行了
bool dfs(int tmp){      //把每一列看成树的一层，dfs
    if(tmp==animals) //到了animals+1层，说明都分配好了 
        return true;
    for (int i = 0; i <= person; i++) // 
        if (used[i][tmp] == false&&love[i][tmp]==1&&cnt[i]>0) {  //这个人可喂并且没用过
            used[i][tmp]=true;cnt[i]--;
            if(dfs(tmp + 1)) //这样可行的话，true就行，因为是有一种可行情况就行
                return true; 
            cnt[i]++; used[i][tmp]=false;  //我傻了，剪枝不了
            }
    return false;
}
 //每个动物分配可以喂养（cnt>0），权重最大的人;贪心，这样后面的动物能够喂养的机会增大 
  //证明: 对于某一个动物a，假如只能由某个人喂，那么他是唯一有权重的;
//会不会出现这个人权值高但是后面某个动物b只能由这个人喂，所以为了节省cnt需要保留权值高的人，要选择权值低的人喂a呢？
// 会。
/*
1 1 1 1 0 1
1 1 1 0 1 0
每人最多喂3个
解是
1    1   1
 1 1   1
但是根据贪心就失败了。所以这个贪心只是可以过但是是错的
*/

bool greedy(){
    double maxcap=0;int per=-1,flag=-1;
    for(int i=0;i<animals;i++)
    {                     
        maxcap=0,per=-1,flag=0;  
        for(int j=0;j<person;j++){  //
            if(capacity[j][i]>maxcap&&cnt[j]>0){   //常见错误，直接==0(double a>b) 应该用eps。但是这里数据在100，精度没那么高直接用也行
                per=j;flag=1;maxcap=capacity[j][i];  //常见错误 ij反了，注意意义！！。就是这里的i是animals而main中求cap的i是person，所以要反过来。所以要注意!!
            }

        }
        if(flag==0) return false;  //常见错误 放错位置，注意在哪个结构({括号)
            cnt[per]--;
    }
    return true;
}


int main(){

    while(scanf("%d%d",&person,&animals)==2){
        for(int i=0;i<person;i++)
            for(int j=0;j<animals;j++)
                cin>>love[i][j];           //是否喜欢
        cin>>maxn;
        for(int i=0;i<person;i++)
            for(int j=0;j<animals;j++)
                used[i][j]==false;
        for(int i=0;i<person;i++)  //每个人的上限
            cnt[i]=maxn;
        for(int i=0;i<person;i++) summ[i]=0; //  初始化
        for(int i=0;i<person;i++)
            for(int j=0;j<animals;j++)
                summ[i]+=love[i][j];  //每个人的总和
        for(int i=0;i<person;i++)  
            for(int j=0;j<animals;j++)  
           capacity[i][j] =1.0*love[i][j]/summ[i]; //权重
        
        if(greedy())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}



//2 网上还找到了网络流的做法  https://github.com/lijiansong/acm-algorithms/blob/master/CodeForces/woj/woj1008.cpp
//好久没用，快忘了都
/*

    参考《算法竞赛入门经典》第11章 网络流初步 
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm> 
using namespace std;
#define N 210                                           //容量和流量之差=残量
int m,n,k,a[N],flow[N][N],capacity[N][N],s,t,f,p[N];  //a[N]从起点到i的可改进量(可增量),也就是残量。残量是s 到i的路径上的最小残量，而非某条边
void MaxFlow()
{
    queue<int> q;
    memset(flow,0,sizeof(flow));
    f=0;
    for(;;)
    {
        memset(a,0,sizeof(a));
        a[s]=0xfffffff;   //从外界到起点的流无限
        q.push(s);
        while(!q.empty())//BFS寻找增广路径 
        {
            int u=q.front();
            q.pop();
            for(int v=1;v<=t;++v)
            {
                //找到新节点v 
                if(!a[v] && capacity[u][v] > flow[u][v])  //残量>0 && 容量大于流量 .
                {
                    p[v]=u;q.push(v);//记录v的父节点，并加入队列
                    a[v]=min(a[u],capacity[u][v]-flow[u][v]);  
                }                                               
            }
        //    if(a[t]) break;
        }
        if(a[t]==0)break;//s到t 残量为0,无法改进
        for(int u=t;u!=s;u=p[u])//从汇点往回走 
        {
            flow[p[u]][u]+=a[t];//更新正向流量 
            flow[u][p[u]]-=a[t];//更新反向流量 
        }
        f+=a[t];//更新从s流出的总流量
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    while(cin>>m>>n)
    {
        memset(capacity,0,sizeof(capacity));
        s=0;
        t=m+n+1;  //增加源点汇点 0 m+n+1 此时 m标号从1开始
        f=0;      //总的流大小
        int ani=m+1,temp;
        for(i=1;i<=m;++i)
        {
            for(j=0;j<n;++j)
            {
                cin>>temp;
                if(temp==1)
                    capacity[i][ani+j]=1;
                capacity[ani+j][t]=1;    //反向边
            }
        }
        cin>>k;
        for(i=1;i<=m;++i)
        {
            capacity[0][i]=k; //源点到每个人的流大小为k,
        }
        MaxFlow();
        if(f==n)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}
*/