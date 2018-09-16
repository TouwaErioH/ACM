#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 20010;
struct Edge
{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
}
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int dp[MAXN],num[MAXN];
int n;
void dfs(int u,int pre)
{
    dp[u] = 0;num[u] = 1;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == pre)continue;
        dfs(v,u);
        dp[u] = max(dp[u],num[v]);
        num[u] += num[v];
    }
    dp[u] = max(dp[u],n - num[u]);
}

int main()
{
    int T;
    scanf("%d",&T);
    int u,v;
    while(T--)
    {
        scanf("%d",&n);
        init();
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1,-1);
        int ans1 = 1, ans2 = dp[1];
        for(int i = 2;i <= n;i++)
            if(ans2 > dp[i])
            {
                ans1 = i;
                ans2 = dp[i];
            }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
