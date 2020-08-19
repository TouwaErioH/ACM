// k短路
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;

#define infinity 0x1fffffff
#define upN 1005
#define upM 10005




struct Edge {
    int v, next, w;
};


struct state {
    int pos, len, h;
    bool operator < (const state &cmp) const {
        if(cmp.len + cmp.h == len + h)  
            return cmp.len < len;
        else                            
            return cmp.len + cmp.h < len + h;
    }
};


Edge node[upM + upN], in_node[upM + upN];
int dis[upN];
bool vis[upN];
int n, m, k, ednum, inednum;


void addedge(int u, int v, int c) {
    ++ ednum;
    node[ednum].next = node[u].next;
    node[u].next = ednum;
    node[ednum].v = v;
    node[ednum].w = c;
}

void in_addedge(int u, int v, int c) {
    ++ inednum;
    in_node[inednum].next = in_node[u].next;
    in_node[u].next = inednum;
    in_node[inednum].v = v;
    in_node[inednum].w = c;
}

bool spfa(int root) {
    queue <int> q;
    for(int i=0;i<upN;i++)
        vis[i]=false;
    for(int i = 1; i <= n; ++ i) dis[i] = infinity;
    vis[root] = true;
    dis[root] = 0;
    q.push(root);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int son = in_node[u].next; son != -1; son = in_node[son].next) {
            int v = in_node[son].v;
            int w = in_node[son].w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int solve(int s, int t, int k) {
    if(dis[s] == infinity)   return -1;
    if(s == t)  ++ k;
    priority_queue <state> q;
    state now;
    now.pos = s, now.len = 0, now.h = dis[s];
    q.push(now);
    int cnt = 0;
    while(!q.empty()) {
        state top = q.top(); q.pop();
        if(top.pos == t) ++ cnt;
        if(cnt == k)    return top.len;
        for(int i = node[top.pos].next; i != -1; i = node[i].next) {
            state tmp;
            tmp.pos = node[i].v, tmp.len = node[i].w + top.len, tmp.h = dis[node[i].v];
            q.push(tmp);
        }
    }
    return -1;
}
int main() {
    int u, v, w;
    while(cin>>n>>m>>k) {
        ednum = n, inednum = n;
        for(int i = 0; i <= m + n; ++ i) {
            node[i].next = in_node[i].next = - 1;
        }
        int tm=m;
        while(tm--){
            cin>>u>>v>>w;
            addedge(u, v, w);
            in_addedge(v, u, w);
        }
        spfa(n);
        int ans = solve(1, n, k);
        cout<<ans<<endl;
    }
    return 0;
}