#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
bool vis[MAXN];
int ans, n, c[MAXN], p[MAXN], minc[MAXN];
void dfs(int u) {                     //判环及求最小值 //mi数组很好
    if(vis[u]) return;
    vis[u] = true;
    int v = p[u];
    if(vis[v] && mi[v] == 0) {
        int mic = c[v];
        for(int i = p[v]; i != v; i = p[i]) mic = min(mic, c[i]);
        ans += mic;
        minc[u] = mic;
    }
    else {
        dfs(v);
        minc[u] = minc[v];
    }

}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", c + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", p + i);
    ans = 0;
    for(int i = 1; i <= n; ++i) dfs(i);
    printf("%d\n", ans);
}
