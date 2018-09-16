#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
int n,m,f[N][30],head[N],cnt,deg[N];
char a[N];
struct Edge{
    int to,next;
}edge[N*2];

void add(int u, int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}

void toposort(){
    queue<int>q;
    for(int i = 1; i <= n; i ++){
        if(!deg[i]){
            q.push(i);
            f[i][a[i-1]-'a'] ++;
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        cnt ++;
        for(int i = head[u]; ~i; i = edge[i].next){
            int v = edge[i].to;
            deg[v] --;
            if(!deg[v]) q.push(v);
            for(int j = 0; j < 26; j ++) f[v][j] = max(f[v][j],f[u][j] + (a[v-1]-'a' == j));
        }
    }
    if(cnt < n) printf("-1\n");
    else{
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < 26; j ++){
                ans = max(ans,f[i][j]);
            }
        }
        printf("%d\n",ans);
    }
}

int main(){
    scanf("%d%d%s",&n,&m,a);
    memset(head,-1,sizeof(head));
    cnt = 0;
    int u,v;
    for(int i = 0; i < m; i ++){
        scanf("%d%d",&u,&v);
        deg[v] ++;
        add(u,v);
    }
    toposort();
    return 0;
}
