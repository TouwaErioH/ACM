#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxq = 100005;
int par[maxn*maxn];
int mapp[maxn][maxn];
int qq[maxq];
int n,m;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct Node
{
	int x,y;
	int val;
}nodes[1005*1005];


int Find(int x)
{
	return x==par[x]?x:par[x]=Find(par[x]);
}


bool cmp(Node a,Node b)
{
	return a.val<b.val;
}

int main()
{
    int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 0;i<n;i++)
			for (int j = 0;j<m;j++)
			{
				scanf("%d",&mapp[i][j]);
				int pos = i*m+j;
				nodes[pos].x=i;
				nodes[pos].y=j;
				nodes[pos].val=mapp[i][j];
			}
		int ans = 0;
		int q;
		scanf("%d",&q);
		for (int i = 0;i<q;i++)
			scanf("%d",&qq[i]);
		memset(par,-1,sizeof(par));
		sort(nodes,nodes+n*m,cmp);
		int k = n*m-1;
		for (int i = q-1;i>=0;i--)
		{
			if (qq[i]< nodes[k].val)
			{
				while (k>=0 && qq[i]<nodes[k].val)
				{
					int pos = nodes[k].x*m+nodes[k].y;
                    if (par[pos]==-1)
						par[pos]=pos,ans++;
					for (int di=0;di<4;di++)
					{
                        int dx = nodes[k].x+dir[di][0];
						int dy = nodes[k].y+dir[di][1];
						if (dx>=0 && dx<n&&dy>=0&&dy<m&&mapp[dx][dy]>qq[i])
						{
							int ppos = dx*m+dy;
						    if (par[ppos]!=-1)
						    {
							   int u = Find(ppos);
							   int v = Find(pos);
							   if (u!=v)
							    	par[u]=v,ans--;
						    }
						}
					}
					k--;
				}
				if (k<0)
				{
					for (;i>=0;i--)
					{
						qq[i]=ans;
					}
					break;
				}
		  	}
			qq[i]=ans;
		 }
	    for (int i = 0;i<q;i++)
			printf("%d ",qq[i]);
		printf("\n");
	}
	return 0;
}
