/*
Ҫ����ֵ�����С·�������Ա����������
ͨ����ǰ���u����С��Ҫ�������Ƴ���һ�����v����С��Ҫ��������
cost[v] = cost[u] + ( cost[u] - 1 ) / 19 + 1 ;
�ֵ���͸��ӷ����ˣ���������·����ÿ�������ĵ㶼�ǹؼ��㣬
����������ͬʱ�ж�֮ǰ�����ǰ�����Լ��������������ǰ�����Ƚ�ȡ��С�����ˡ�
���յ����ƣ�d[u]��ʾ����u�Ժ�ʣ�µĻ����ô����u֮ǰ�Ļ���������Ϊy,d[u] = x,
��ôy-x=ceil(y/20.0)=(y-1)/20+1=(y+19)/20��
(y-x)*20+r=y+19��0��r��19����19*y=20*x+r����������yӦ�þ���С��x�Ĳ����ǲ��ܱ䶯�ģ�
����y=x+ceil(x/19.0)��
Ȼ��������һ���ֵ�����С��·�����ɣ���Ϊÿ����ĸ���Ƕ�һ�޶��ģ����Բ���bfs��ÿ�μ�¼һ����͹��ˡ�
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
    tp[id_cnt] = 'a'<=c&&c<='z';//д��isalpha(c)-1;WA��
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
