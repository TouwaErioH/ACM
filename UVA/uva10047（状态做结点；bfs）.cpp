#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char a[30][30];
int vis[30][30][4][5];
int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct node{
    int x,y,di,co,t;
    node(int xx,int yy,int d,int c,int st)
    {
        x=xx;y=yy;di=d;co=c;t=st;
    }
};
queue<node> q;
void bfs()
{
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(a[u.x][u.y]=='T'&&u.co==0)
        {
            printf("minimum time = %d sec\n",u.t);
            return;
        }
        int x=u.x,y=u.y,co=u.co;
        int di=(u.di+1)%4;//向右转
        if(!vis[x][y][di][co])
        {
            vis[x][y][di][co]=1;
            q.push(node(x,y,di,co,u.t+1));
        }
        di=(u.di+3)%4;//向左转
        if(!vis[x][y][di][co])
        {
            vis[x][y][di][co]=1;
            q.push(node(x,y,di,co,u.t+1));
        }
        di=u.di;//前进
        x+=dx[di];y+=dy[di];
        co=(co+1)%5;//下一种颜色
        if(x<n&&x>=0&&y<m&&y>=0&&a[x][y]!='#'&&!vis[x][y][di][co])
        {
            q.push(node(x,y,di,co,u.t+1));
            vis[x][y][di][co]=1;
        }
    }
    printf("destination not reachable\n");
}
int main()
{
    int ss=1;
    while(scanf("%d%d",&n,&m)&&n)
    {
        if(ss>1) printf("\n");
        memset(vis,0,sizeof(vis));
        while(!q.empty()) q.pop();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='S')
                {
                    q.push(node(i,j,0,0,0));
                    vis[i][j][0][0]=1;
                }
            }
        printf("Case #%d\n",ss++);
        bfs();
    }
    return 0;
}
