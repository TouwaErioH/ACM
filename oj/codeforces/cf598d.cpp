#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char mapp[maxn][maxn];
int vis[maxn][maxn];
int num[maxn*maxn];
int ans,id=0,m,n;
void dfs(int x,int y)
{
	int nx,ny;
	vis[x][y]=id;
	for (int i = 0;i<4;i++)
	{
		nx = x+dir[i][0];
	    ny = y+dir[i][1];
	    if (nx>0 && nx<=n && ny>0 && ny<=m && !vis[nx][ny])
		{
			if (mapp[nx][ny] == '*')
				ans++;
			else
				dfs(nx,ny);
		}
	}
}
int main()
{
	int k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i<=n;i++)
		scanf("%s",mapp[i]+1);
	memset(vis,0,sizeof(vis));
	for (int i = 1;i<=n;i++)
		for (int j = 1;j<=m;j++)
			if (mapp[i][j] == '.' && !vis[i][j])
			{
				ans = 0;
				id++;
				dfs(i,j);
				num[id]=ans;
			}
	while (k--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
        printf("%d\n",num[vis[x][y]]);
	}
	return 0;
}
