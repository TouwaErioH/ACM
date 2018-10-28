#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=205;
int r[55],c[55],p[55],d[55],s[55];
struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];         // 是否在队列中
  int d[maxn];           // Bellman-Ford
  int p[maxn];           // 上一条弧
  int a[maxn];           // 可改进量

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void Addedge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BellmanFord(int s, int t,int& flow, int& cost) {
    for(int i = 0; i < n; i++) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = 0;
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
        }
      }
    }
    if(d[t] == INF) return false;
    flow += a[t];
    cost += d[t] * a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    return true;
  }

  // 需要保证初始网络中没有负权圈
  int MincostFlow(int s, int t,int& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s, t,flow, cost));

    return flow;
  }

};

MCMF g;

int main ()
{
    int u,j,T,C,R,ans,n;
    scanf("%d",&T);
    for(int kase=1; kase<=T; kase++)
    {
        ans=0;
        int cnt=0;
        scanf("%d%d%d",&n,&C,&R);
        g.init(2*n+3);                   //init 一开始搞成2*n+2了...囧
        for(int i=1; i<=n; i++)
            scanf("%d",&r[i]),ans+=r[i];
        for(int i=1; i<=C; i++)
            scanf("%d%d",&c[i],&p[i]);
        for(int i=1; i<=R; i++)
            scanf("%d%d",&d[i],&s[i]);


         for(int i=1; i<=C; i++)
            g.Addedge(0,2*n+1,c[i],p[i]);
            for(int i=1; i<n; i++)
            g.Addedge(i,i+1,INF,0);

        for(int i=1; i<=n; i++)
            g.Addedge(0,i,r[i],0);
        for(int i=n+1; i<=2*n; i++)
            g.Addedge(i,(n+1)*2,r[i-n],0);
        for(int i=n+1; i<=2*n; i++)
            g.Addedge(2*n+1,i,INF,0);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=R; j++)
            {
                if(i+d[j]+1<=n) g.Addedge(i,i+d[j]+1+n,INF,s[j]);
            }
        }
        int cos;
        int f=g.MincostFlow(0,2*n+2,cos);

        printf("Case %d: ",kase);
        if(f!=ans)
            printf("impossible\n");
        else
            printf("%d\n",cos);
    }
    return 0;
}
/*
2
3 2 1
10 20 30
40 90 15 100
1 5
*/
