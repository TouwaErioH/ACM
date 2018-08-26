/*
�����ϵ��⣬��ͼ���൱���ÿ������8���㣨r, c, dir, doubled)��
�ֱ��ʾ��һ�����������ҵ��ĸ������ƶ�������㣬�Լ��ƶ����õ�Ȩֵ�Ƿ�ӱ���
ÿ������4����̵㣬�ֱ��Ӧ���������ң������һ���ķ������̵㷽��һ�£�
��Ҫ�ӱ�����ϸ��㵽���Ȩֵ���������һ����Ȩֵû�мӱ����ͼӱ���һ����Ȩֵ��
����ͼ�ɹ���ֱ����dij()�㷨�����㵽��������ʱ�䣬���ͳ�Ƶ��յ�Ĵ�ʱ��
�ر�Ҫע�⣬���ڵ��յ�ҲҪ�ӱ�Ȩֵ�������û�ӱ��ģ�Ҫ����ȥ��
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e5;
const int inf=1e9;
struct HeapNode
{
	int d,u;
	bool operator<(const HeapNode& rhs)const
	{
		return d>rhs.d;
	}
};
struct Edge
{
	int from,to,dist;
};
struct Dijkstra
{
	int n,m;
	vector<Edge>edges;
	vector<int>G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];

	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	}

	void AddEdge(int from,int to,int dist)
	{
		edges.push_back((Edge){from,to,dist});
		m=edges.size();
		G[from].push_back(m-1);
	}

	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		for(int i=0;i<n;i++)d[i]=inf;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while(!Q.empty())
		{
			HeapNode x=Q.top();Q.pop();
			int u=x.u;
			if(done[u])continue;
			done[u]=true;
			for(int i=0;i<G[u].size();i++)
			{
				Edge& e=edges[G[u][i]];
				if(d[e.to]>d[u]+e.dist)
				{
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
				}
			}
		}
	}
};
const int UP=0,LEFT=1,DOWN=2,RIGHT=3;
const int inv[4]={2,3,0,1};
const int dr[4]={-1,0,1,0};
const int dc[4]={0,-1,0,1};
const int maxr=100;
const int maxc=100;
int grid[maxr][maxc][4];
int R,C,n,id[maxr][maxc][4][2];
int ID(int r,int c,int dir,int doubled)
{
	int& x=id[r][c][dir][doubled];
	if(x==0)x=++n;
	return x;
}
bool cango(int r,int c,int dir)
{
	if(r<0||r>=R||c<0||c>=C)return false;
	return grid[r][c][dir]>0;
}
int readint()
{
	int x;scanf("%d",&x);return x;
}
Dijkstra solver;
int main()
{
	int r1,c1,r2,c2,kase=0;
	while(scanf("%d%d%d%d%d%d",&R,&C,&r1,&c1,&r2,&c2)==6&&R)
	{
		r1--,c1--,r2--,c2--;
		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C-1;c++)
			grid[r][c][RIGHT]=grid[r][c+1][LEFT]=readint();
			if(r!=R-1)
			for(int c=0;c<C;c++)
			grid[r][c][DOWN]=grid[r+1][c][UP]=readint();
		}
		solver.init(R*C*8+1);
		n=0;
		memset(id,0,sizeof(id));
		for(int dir=0;dir<4;dir++)if(cango(r1,c1,dir))
		solver.AddEdge(0,ID(r1+dr[dir],c1+dc[dir],dir,1),grid[r1][c1][dir]*2);
		//����ÿ��״̬(r,c,dir,doubled)�ĺ��״̬
		for(int r=0;r<R;r++)
		for(int c=0;c<C;c++)
		for(int dir=0;dir<4;dir++)if(cango(r,c,inv[dir]))
		for(int newdir=0;newdir<4;newdir++)if(cango(r,c,newdir))
		for(int doubled=0;doubled<2;doubled++)
		{
			int newr=r+dr[newdir];
			int newc=c+dc[newdir];
			int v=grid[r][c][newdir],newdoubled=0;
			if(dir!=newdir)
			{
				if(!doubled)v+=grid[r][c][inv[dir]];
				newdoubled=1,v+=grid[r][c][newdir];
			}
			solver.AddEdge(ID(r,c,dir,doubled),ID(newr,newc,newdir,newdoubled),v);
		}
		solver.dijkstra(0);
		int ans=inf;
		for(int dir=0;dir<4;dir++)if(cango(r2,c2,inv[dir]))
		for(int doubled=0;doubled<2;doubled++)
		{
			int v=solver.d[ID(r2,c2,dir,doubled)];
			if(!doubled)v+=grid[r2][c2][inv[dir]];
			ans=min(ans,v);
		}
		printf("Case %d: ",++kase);
		if(ans==inf)printf("Impossible\n");
		else printf("%d\n",ans);
	}
}
