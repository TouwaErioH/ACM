#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 110;
#define inf 1<<30
int n;
int a[maxn],p[maxn];
struct edge
{
	int from,to,w,cap,flow;
	edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){
	}
};
vector<edge> edges;
vector<int> g[maxn];
void init(int k)
{
    		for(int i=0;i<=k;i++)g[i].clear();
		edges.clear();
}

void addedge(int from,int to,int cap)
{
	edges.push_back(edge(from,to,cap,0));
	edges.push_back(edge(to,from,cap,0));
	int m=edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
int Max_flow(int s,int t)
{
	int flow=0;
	while(1)
	{
		queue<int> q;
		memset(a,0,sizeof(a));
		q.push(s);
		a[s]=inf;
		while(!q.empty())
		{
			int x = q.front();q.pop();
			for(int i=0;i<g[x].size();i++)
			{
				edge &e=edges[g[x][i]];
				if(!a[e.to]&&e.cap>e.flow)
				{
					p[e.to]=g[x][i];
					a[e.to]= min(a[x],e.cap-e.flow);
					q.push(e.to);
				}
			}
			if(a[t])break;
		}
		if(!a[t])break;
		for(int i=t;i!=s;i=edges[p[i]].from)
		{
			edges[p[i]].flow+=a[t];
			edges[p[i]^1].flow-=a[t];
		}
		flow+=a[t];
	}
	return flow;
}
int main()
{
	int cas = 0;
	while(scanf("%d",&n)&&n)
	{
		int s,t,c;
		int u,v,cap;
		init(n);
		scanf("%d%d%d",&s,&t,&c);
		for(int i=0;i<c;i++)
		{
			scanf("%d%d%d",&u,&v,&cap);
			addedge(u,v,cap);
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",++cas,Max_flow(s,t));
	}
}
