#include<cstdio>
#include<cstring>
const int maxn = 105;
int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;

bool dfs(int u){
  c[u] = -1;
  for(int v = 1; v <=n; v++)
    if(G[u][v])
    {
    if(c[v]<0) return false;//正在访问，存在有向环
    else if(!c[v]) dfs(v);
    }
  c[u] = 1; topo[t--]=u;
  return true;
}

bool toposort(){
  t = n;
  memset(c, 0, sizeof(c));
  for(int u = 1; u <=n; u++) if(!c[u])
    if(!dfs(u)) return false;
  return true;
}

int main() {
  while(scanf("%d%d", &n, &m) == 2 && n) {
    memset(G, 0, sizeof(G));
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u][v] = 1;
    }
    if(toposort()) {
      for(int i = 1; i <n; i++)
        printf("%d ", topo[i]);
      printf("%d\n", topo[n]);
    }
    else
      printf("No\n");
  }
  return 0;
}
