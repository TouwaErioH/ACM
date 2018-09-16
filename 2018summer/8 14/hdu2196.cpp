#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000+200;
struct edge
{
    int to;//终端点
    int next;//下一条同样起点的边号
    int w;//权值
} edges[MAXN*2];
int tot;//总边数
int head[MAXN];//head[u]=i表示以u为起点的所有边中的第一条边是 i号边
void add_edge(int u,int v,int w)//添加从u->v，权值为w的边
{
    edges[tot].to=v;
    edges[tot].w=w;
    edges[tot].next = head[u];
    head[u] = tot++;
}
int dist[MAXN][3];//dist[i][0,1,2]分别为正向最大距离，正向次大距离，反向最大距离
int longest[MAXN];
int dfs1(int u,int fa)//返回u的正向最大距离
{
    if(dist[u][0]>=0)return dist[u][0];
    dist[u][0]=dist[u][1]=dist[u][2]=longest[u]=0;

    for(int e=head[u]; e!=-1; e=edges[e].next)
    {
        int v= edges[e].to;
        if(v==fa)continue;

        if(dist[u][0]<dfs1(v,u)+edges[e].w)
        {
            longest[u]=v;
            dist[u][1] = max(dist[u][1] , dist[u][0]);
            dist[u][0]=dfs1(v,u)+edges[e].w;
        }
        else if( dist[u][1]< dfs1(v,u)+edges[e].w )//这里一定要记得，要不然无情WA
            dist[u][1] = max(dist[u][1] , dfs1(v,u)+edges[e].w);
    }
    return dist[u][0];
}
void dfs2(int u,int fa)
{
    for(int e=head[u];e!=-1;e=edges[e].next)
    {
        int v = edges[e].to;
        if(v==fa)continue;
        if(v==longest[u]) dist[v][2] = max(dist[u][2],dist[u][1])+edges[e].w;
        else dist[v][2] = max(dist[u][2],dist[u][0])+edges[e].w;
        dfs2(v,u);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        tot=0;
        memset(dist,-1,sizeof(dist));
        memset(head,-1,sizeof(head));
        memset(longest,-1,sizeof(longest));
        for(int i=2; i<=n; i++)
        {
            int v,w;
            scanf("%d%d",&v,&w);
            add_edge(i,v,w);//加边
            add_edge(v,i,w);//加边
        }
        dfs1(1,-1);
        dfs2(1,-1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dist[i][0],dist[i][2]));
    }
    return 0;
}
