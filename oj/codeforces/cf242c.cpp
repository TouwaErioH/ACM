#include<iostream>   //bfs
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
    int x0,y0,x1,y1,n;
    queue<pair<int,int> >q;//开了一个pair的队列
    map<pair<int,int>,int>m;//把pair类型的映射成一个数
int main(){
    int r,a,b;
    int i,j;
    int x,y,nx,ny;
    int next[8][2]={ {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
    while(scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&n)!=EOF){
        while(!q.empty()) q.pop();
        m.clear();
        while(n--){
            scanf("%d%d%d",&r,&a,&b);//r行的a~b列是可以走的路。
            for(i=a;i<=b;i++){
                m[make_pair(r,i)]=-1;//把可以走的点映射成-1
            }
        }
            m[make_pair(x0,y0)]=0;//起点的步数为0
            q.push(make_pair(x0,y0));//起点入队列
            while(!q.empty()){
                x=q.front().first;//队列莉第一个数据的第一个数
                y=q.front().second;//队列莉第一个数据的第二个数

                q.pop();
                for(i=0;i<8;i++){
                nx=x+next[i][0];
                ny=y+next[i][1];
                if(m[make_pair(nx,ny)]<0){//判断这个点是否可以走的
                    m[make_pair(nx,ny)]=m[make_pair(x,y)]+1;//步数+1
                    q.push(make_pair(nx,ny));
                }
            }
            }
        printf("%d\n",m[make_pair(x1,y1)]);//如果这个点走不到就会是-1（这也是为什么映射成-1的原因），走到存的就是最短路
    }
    return 0;   //想象一下就知道这是从起点向外扩散，每个格的数字代表从起点到那里的最短步数；终点不一定最后走到，但一定是最短路
}
