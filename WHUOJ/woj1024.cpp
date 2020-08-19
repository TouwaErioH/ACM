/*
给一棵树(节点间只有一条路(可能无边)),节点间边有正权。求从任一节点开始遍历这棵树所有点的最小权（节点可重复经过）

 笔记加一条 数据结构-树的性质。树性质是向上只有一个节点，向下有没有限制个节点。(好像没什么用)，
画图知道无论从哪个点开始沿一条边出发，把经过这条边可以到达的点看成集合A，整个树为集合T，要想去T-S，必然要原路返回到起始点
(就是说把这个点砍了就是二分图)。所以这题看成两个过程，先是从起始点s遍历A,然后从最后到的点返回到起始点s，再遍历T-S
然后再画图可知从哪个点开始都是一样的(大雾，不一样!)


然后我感觉做过这种题，搜了一下想起来了,只需要找到树的直径然后直径上其他的树枝走两遍就行了，直径只走一遍
然后转化为无根树求直径的问题.
两次DFS/BFS都可以。任选一点做DFS，找到的最长点再做DFS，再次找到的最长点就是直径
//当然最短路Bellmanford 等算法也可以

POJ1985+POJ2631
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct Node{
    int v,d;   
};

int n,dis[50001];
vector<Node> tree[50001];
Node tmp1,tmp2;
int T,casee=0;
int u,v,d,i,ans,faresta,tpans;

int BFS(int x)
{
	for(i=0;i<=n;i++) //n.输入点的index到了n,一开始顺手写成n-1了
        dis[i]=0;
    int vis[n+5];
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(x);
	vis[x]=1;
	int point = 1;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
        if(dis[f]>tpans)
		{
		    tpans = dis[f];
			point = f;
        }
		for(i=0;i<tree[f].size();i++)
		{
			Node tmp = tree[f][i];
			if(vis[tmp.v]==0)
			{
				vis[tmp.v]=1;
				dis[tmp.v] = dis[f] + tmp.d;
				q.push(tmp.v);
			}
		}
	}
	return point;
}


void build(){
    for(i=1;i<=n;i++)
        tree[i].clear();
        ans=0;
        for(i=0;i<n-1;i++){
            cin>>u>>v>>d;
            tmp1.v=v;tmp1.d=d;
            tmp2.v=u;tmp2.d=d;
            tree[u].push_back(tmp1);  //相连的边,点
            tree[v].push_back(tmp2);
            ans=ans+2*d;
        }
    return;
}

int main(){

    cin>>T;
    while(T--){
        ans=0;
        if(casee!=0)
            cout<<endl;
        casee++;
        cin>>n;
        build();

        tpans=0;
        faresta=BFS(1);
        tpans=0;
        BFS(faresta);
        printf("Case %d:\n",casee);
        cout<<ans-tpans<<endl;
    }
    system("pause");
    return 0;
}
