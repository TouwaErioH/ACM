#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1000050;
const long long INF = 1ll<<61;  //����һ��ʼ����0x3f3f3f3f...sb��

struct qnode
{
    int v;
    long long c;
    qnode(int v=0,long long c=0):v(v),c(c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int to;
    int w,MIN;
    Edge(int to,int w,int MIN):to(to),w(w),MIN(MIN){}
};

vector<Edge>E[maxn];
bool vis[maxn];
long long dis[maxn];

void Dijstra(int n,int start)
{
    memset(vis,false,sizeof(vis));    //nima,һ��ʼ��ֵ��-1��....
    for(int i=1;i<=n;i++)
        dis[i] = INF;
    priority_queue<qnode> que;
     while(!que.empty()) que.pop();
    dis[start] = true;
    que.push(qnode(start,1));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u])
            continue;
        vis[u] = 1;
        for(int i=0;i<E[u].size();i++)
        {
            int v = E[u][i].to;
            int a = E[u][i].w;
            if(log2((dis[u]+a*1.0) / dis[u]*1.0)<E[u][i].MIN)
            //if((a/dis[u])<E[u][i].MIN)     //���ﲻ��1.0Ҳ����
                continue;
            if(!vis[v]&&dis[v]>dis[u]+a)   //����ģ�VIS��Ҫ
            {
                dis[v] = dis[u] + a;
                que.push(qnode(v,dis[v]));
            }
        }
    }
    if(dis[n]==INF)
        printf("-1\n");
    else
        printf("%d\n",(int)log2(dis[n]*1.0));
}

int main()
{
    int t,m,u,v,n;
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            E[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&a,&b);
            //b=(1ll<<b)-1;
            E[u].push_back(Edge(v,a,b));
        }
        Dijstra(n,1);
    }
    return 0;
}
