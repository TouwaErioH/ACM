#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;
int n,m;
vector <int> ans;
const LL INF = 0x3f3f3f3f;
const int MAXN = 2e6+5;
struct qnode
{
    int v;
    LL c;
    qnode (int _v = 0, LL _c = 0) : v(_v), c(_c) {}
    bool operator < (const qnode &r) const { return c > r.c; }
};
struct Edge
{
    int v;
    LL cost;
    Edge (int _v = 0,LL _cost = 0) : v(_v), cost (_cost){}
};
vector <Edge> E[MAXN];
bool vis[MAXN];
LL dist[2][MAXN];
void dijkstra(int n,int start,int poi) //点从编号1开始
{
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= MAXN; i++) dist[poi][i] = INF;
    priority_queue <qnode> que;
    while(!que.empty()) que.pop();
    dist[poi][start] = 0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++)
        {
            int v = E[tmp.v][i].v;
            LL cost = E[u][i].cost;
            if (!vis[v] && dist[poi][v] > dist[poi][u] + cost)
            {
                dist[poi][v] = dist[poi][u] + cost;
                que.push(qnode(v,dist[poi][v]));
            }
        }
    }
}
void addedge(int u,int v,LL w)
{
    E[u].push_back(Edge(v,w));
}

int main(){
    int T;
    cin >> T;
    int cas = 1;
    while(T--)
    {
        for (int i = 0; i < MAXN; i++)
        {
            E[i].clear();
        }
        scanf("%d%d",&n,&m);
        int pos = n;    //用于记录新创建的点
        while(m--)
        {
            LL t;
            int s;
            scanf("%lld%d",&t,&s);
            pos++;
            while(s--)
            {
                int u;
                scanf("%d",&u);
                addedge(u,pos,t);
                addedge(pos,u,t);
            }
        }
        dijkstra(pos,1,0);  //从1出发，结果保存在dist[0][]中
        dijkstra(pos,n,1); //从n出发，结果保存在dist[1][]中
        LL mindis = INF;
        ans.clear();
        for (int i = 1; i <= n; i++)
        {
            mindis = min(mindis,max(dist[0][i],dist[1][i]));
        }
        if (mindis == INF) printf("Case #%d: Evil John\n",cas++);
        else
        {
            printf("Case #%d: %lld\n",cas++,mindis / 2);
            for (int i = 1; i <= n; i++)
            {
                if (mindis == max(dist[0][i],dist[1][i]))
                {
                    ans.push_back(i);
                }
            }
            printf("%d",ans[0]);
            for (int i = 1; i < ans.size(); i++)
            {
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
    1.点数N=n+2*最大集合数=1e5+2e6
    2.边数M=2*最大集合数=2e6
    3.要用LL存t和dist
*/
