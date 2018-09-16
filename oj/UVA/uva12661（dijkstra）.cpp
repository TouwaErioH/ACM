#include<bits/stdc++.h>
using namespace std;
typedef int ll;

const int maxn = 301,maxm = 5e4+1;

int n,m,s,t;

struct Edge
{
    int v,t,a,b,nxt;
    void read(int pa){
        scanf("%d%d%d%d",&v,&a,&b,&t);
        nxt = pa;
    }
}edges[maxm];

int head[maxn],ecnt;
ll d[maxn];

int cost(int u,Edge& e)
{
    int r = d[u]%(e.a+e.b);
    if(e.a-r>=e.t) return e.t;
    return e.a+e.b-r+e.t;
}

struct Node
{
    ll d;
    int u;
    bool operator < (const Node& x) const{
        return d > x.d;
    }
};

ll dijkstra()
{
    priority_queue<Node> q;
    memset(d,0x3f,sizeof(d));
    q.push(Node{0,s});
    d[s] = 0;
    while(q.size()){
        Node x = q.top(); q.pop();
        if(x.u == t) return d[t];
        if(x.d != d[x.u]) continue;
        for(int i = head[x.u]; ~i; i = edges[i].nxt){
            Edge &e = edges[i];
            int dist = cost(x.u,e);
            if(d[e.v] > d[x.u] + dist){
                d[e.v] = d[x.u] + dist;
                q.push(Node{d[e.v],e.v});
            }
        }
    }
    return -1;
}

void init()
{
    memset(head,-1,sizeof(head));
    ecnt = 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int kas = 0;
    while(~scanf("%d%d%d%d",&n,&m,&s,&t)){
        init();
        while(m--){
            int u; scanf("%d",&u);
            edges[ecnt].read(head[u]);
            if(edges[ecnt].a >= edges[ecnt].t) head[u] = ecnt++;
        }
        printf("Case %d: %d\n",++kas,dijkstra());
    }
    return 0;
}
