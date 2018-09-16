/*
要输出字典序最小路径，所以必须逆向求解
通过当前结点u的最小需要货物量推出下一个结点v的最小需要货物量。
cost[v] = cost[u] + ( cost[u] - 1 ) / 19 + 1 ;
字典序就更加方便了，倒着来的路，则每次遇到的点都是关键点，
遇到花费相同时判断之前保存的前驱，以及刚来到这个结点的前驱，比较取最小就行了。
从终点逆推，d[u]表示进入u以后剩下的货物，那么进入u之前的货物数量设为y,d[u] = x,
那么y-x=ceil(y/20.0)=(y-1)/20+1=(y+19)/20。
(y-x)*20+r=y+19，0≤r≤19，即19*y=20*x+r，根据题意y应该尽量小，x的部分是不能变动的，
所以y=x+ceil(x/19.0)。
然后从起点找一条字典序最小的路径即可，因为每个字母都是独一无二的，所以不必bfs，每次记录一个点就够了。
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 54, maxm = maxn*maxn, town = 0, village = 1;
bool g[maxn][maxn];
int head[maxn],nxt[maxm],to[maxm],ecnt;
int tp[maxn];
int id[256];
char rid[256];

void addEdge(int u,int v)
{
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}
int id_cnt;

void init()
{
    memset(head,-1,sizeof(head));
    memset(id,-1,sizeof(id));
    memset(g,0,sizeof(g));
    ecnt = 0;
    id_cnt = 0;
}

inline int ID(char c) {
    if(~id[c]) return id[c];
    id[c]= id_cnt;
    rid[id_cnt] = c;
    tp[id_cnt] = 'a'<=c&&c<='z';//写成isalpha(c)-1;WA了
    return id_cnt++;
}
typedef long long ll;
typedef pair<ll,int> Node;
#define fi first
#define se second

ll d[maxn];
void dijkstra(int s,ll p)
{
    memset(d,0x7f,sizeof(d));
    priority_queue<Node,vector<Node>,greater<Node> > q;
    q.push(Node(d[s] = p,s));
    while(q.size()){
        Node x = q.top(); q.pop();
        int u = x.se;
        if(d[u] != x.fi) continue;
        ll t = (tp[u]?(1+d[u]):((d[u]+18)/19+d[u]));
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            if(d[v] > t ){
                q.push(Node(d[v]= t,v));
            }
        }
    }
}

ll cost(int u,int v)
{
    return tp[v]?1:((d[u]+19)/20);
}

void FindPath(int s,int e)
{
    int u = s;
    while(u != e){
        printf("%c-",rid[u]);
        int nex = -1;
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            if(d[u]- cost(u,v) >= d[v]){
                if(~nex) {
                    if(rid[v] < rid[nex]) nex = v;
                }else nex = v;
            }
        }
        swap(nex,u);
    }
    printf("%c\n",rid[e]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    char a[10],b[10];
    int kas = 0;
    while(scanf("%d",&n),~n){
        init();
        while(n--){
            scanf("%s%s",a,b);
            int u = ID(*a), v = ID(*b);
            if(!g[u][v]){
                g[u][v] = g[v][u] = true;
                addEdge(u,v); addEdge(v,u);
            }
        }
        ll p;
        scanf("%lld%s%s",&p,a,b);
        int s = ID(*a),e = ID(*b);
        dijkstra(e,p);
        printf("Case %d:\n%lld\n",++kas,d[s]);
        FindPath(s,e);
    }
    return 0;
}
