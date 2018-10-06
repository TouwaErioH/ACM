#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10000;
const int maxm = 200000;  //为啥开这么大....用100005re

int head[maxn],to[maxm],nxt[maxm],col[maxn],ecnt,deg[maxn];
int vis[maxn];
int k;
void addEdge(int u,int v)
{
    deg[u]++;
    k=max(k,deg[u]);
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}
void dfs(int u)
{
    for(int i = head[u]; i!=-1; i= nxt[i])
        vis[col[to[i]]] = u;  //u的连接点的颜色都标记为u，不能用

    for(int i = 1; i <= k; i++)
        if(vis[i] != u)
        {
            col[u] = i;
            break;
        }

    for(int i = head[u]; i!=-1; i= nxt[i]){
        if(col[to[i]]) continue;
        dfs(to[i]);
    }
}

int main()
{
    int n,m;
    while(scanf("%d",&n)==1){
            k=0;
        scanf("%d",&m);
        memset(head,-1,sizeof(head));
        memset(deg,0,sizeof(deg));
        memset(col,0,sizeof(col));
        ecnt = 0;

        while(m--){
            int u,v;
            scanf("%d %d",&u,&v);
            addEdge(u,v); addEdge(v,u);
        }

        k = k|1;
        memset(vis,0,sizeof(vis));

        dfs(1);
        printf("%d\n",k);
        for(int i = 1; i <= n; i++)
            printf("%d\n",col[i]);
        cout<<endl;
    }
    return 0;
}
