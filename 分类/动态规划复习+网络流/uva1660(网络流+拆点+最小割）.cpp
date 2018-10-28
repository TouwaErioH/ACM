#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 100 + 5;
const int INF = 0x3f3f3f3f;

 struct Edge {
     int from, to, cap, flow;
     Edge(int u, int v, int c, int f):from(u), to(v), cap(c), flow(f) {}
 };

 struct EdmondsKarp {
     int n, m;
     vector<Edge> edges;
     vector<int> G[maxn];
     int a[maxn];
     int p[maxn];

     void init(int n) {
         for (int i = 0; i < n; i++) G[i].clear();
         edges.clear();
     }

     void AddEdge(int from, int to, int cap) {
         edges.push_back(Edge(from, to, cap, 0));
         edges.push_back(Edge(to, from, 0, 0));
         m = edges.size();
         G[from].push_back(m - 2);
         G[to].push_back(m - 1);
     }

     int Maxflow(int s, int t) {
         int flow = 0;
         for (;;) {
             memset(a, 0, sizeof(a));
             queue<int> Q;
             Q.push(s);
             a[s] = INF;
             while (!Q.empty()) {
                int x = Q.front(); Q.pop();
                 for (int i = 0; i < G[x].size(); i++) {
                     Edge& e = edges[G[x][i]];
                     if (!a[e.to] && e.cap > e.flow) {
                         p[e.to] = G[x][i];
                         a[e.to] = min(a[x], e.cap - e.flow);
                         Q.push(e.to);
                     }
                 }
                 if (a[t]) break;
             }
             if (!a[t]) break;
            for (int u = t; u != s; u = edges[p[u]].from) {
                 edges[p[u]].flow += a[t];
                 edges[p[u] ^ 1].flow -= a[t];
             }
             flow += a[t];
         }
         return flow;
     }
 };

 EdmondsKarp g;
 vector<Edge> bak;         //恢复

 int main() {
    int n,m;
    int u,v;
    while (scanf("%d%d", &n, &m) == 2) {

         g.init(n * 2);
        for (int i = 0; i < n; i++)
            g.AddEdge(i, i + n, 1);

       for (int i = 0; i < m; i++) {
            scanf(" (%d,%d)", &u, &v);   //学到了
             g.AddEdge(u + n, v, INF);

            g.AddEdge(v + n, u, INF);

       }

        int s = n, flow = n;
        bak = g.edges;

        for (int i = 1; i < n; i++) {       //枚举终点
                g.edges = bak;
                flow = min(flow, g.Maxflow(s, i));
        }
        printf("%d\n", flow);
    }
    return 0;
}


/*
5 7 (0,1) (0,2) (1,3) (1,2) (1,4) (2,3) (3,4)*/
