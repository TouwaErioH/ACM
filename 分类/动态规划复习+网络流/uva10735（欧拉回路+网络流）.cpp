#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f):from(u),to(v),cap(c),flow(f) {}
};

const int maxn = 100+10;

struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;    // ����������
  vector<int> G[maxn];   // �ڽӱ�G[i][j]��ʾ���i�ĵ�j������e�����е����
  int a[maxn];           // ����㵽i�ĿɸĽ���
  int p[maxn];           // ���·����p���뻡���

  void init(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for(;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if(!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap-e.flow);
            Q.push(e.to);
          }
        }
        if(a[t]) break;
      }
      if(!a[t]) break;
      for(int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

EdmondsKarp g;

const int maxm = 500 + 5;

int n, m, u[maxm], v[maxm], directed[maxm], id[maxm], diff[maxn];


vector<int> G[maxn];
vector<int> vis[maxn];
vector<int> path;

void euler(int u) {
  for(int i = 0; i < G[u].size(); i++)
    if(!vis[u][i]) {
      vis[u][i] = 1;
      euler(G[u][i]);
      path.push_back(G[u][i]+1);
    }
}

void print_answer() {
  // build the new graph
  for(int i = 0; i < n; i++) { G[i].clear(); vis[i].clear(); }
  for(int i = 0; i < m; i++) {
    bool rev = false;
    if(!directed[i] && g.edges[id[i]].flow > 0)   //id��¼���������edges�е�λ��
        rev = true;                                  //G��¼�ߵ�����Ӧ���յ�
    if(!rev)                          //û�б䷴��
        { G[u[i]].push_back(v[i]);
          vis[u[i]].push_back(0);
        }
    else {
         G[v[i]].push_back(u[i]);
         vis[v[i]].push_back(0);
         }
  }

  // print euler tour
  path.clear();
  euler(0);             //��Ϊ�ڵ�һ��Ϊ��0

  printf("1");
  for(int i = path.size()-1; i >= 0; i--) printf(" %d", path[i]);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &n, &m);
    g.init(n+2);

    memset(diff, 0, sizeof(diff));
    for(int i = 0; i < m; i++) {
      char dir[9];
      scanf("%d%d%s", &u[i], &v[i], dir);
      u[i]--;
      v[i]--;
      directed[i] = (dir[0] == 'D' ? 1 : 0);
      diff[u[i]]++;                             //����-���
      diff[v[i]]--;
      if(!directed[i]) { id[i] = g.edges.size(); g.AddEdge(u[i], v[i], 1); }
    }

    bool ok = true;
    for(int i = 0; i < n; i++)
      if(diff[i] % 2 != 0) { ok = false; break; }

    int s = n, t = n+1;
    if(ok) {
      int sum = 0;
      for(int i = 0; i < n; i++) {

        if(diff[i] > 0) {
        g.AddEdge(s, i, diff[i]/2);
        sum += diff[i]/2;
         }

        if(diff[i] < 0) {
                g.AddEdge(i, t, -diff[i]/2); }
         }

      if(g.Maxflow(s, t) != sum)
        ok = false;
    }

    if(!ok)
        printf("No euler circuit exist\n");
    else
        print_answer(); // underlying graph is always connected

    if(T)
        printf("\n");
  }
  return 0;
}
