
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int inf=1<<29;
const int maxn=100100;
int e,n,m,s,t,head[maxn],nxt[maxn],cost[maxn],a[maxn],b[maxn],pnt[maxn],dis[maxn];
bool vis[maxn];
queue<int >q;
void addedge(int u,int v,int c,int sa,int sd)
{
    pnt[e]=v;
    nxt[e]=head[u];
    cost[e]=c;
    a[e]=sa;
    b[e]=sd;
    head[u]=e++;
}

int spfa(int st,int des)
{
    for(int i=0;i<=n;i++)
    dis[i]=inf;
    dis[st]=0;
    memset(vis,0,sizeof(vis));
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(int i=head[u];i!=-1;i=nxt[i])
        {
            int v=pnt[i];
            int val=dis[u],s=dis[u];
            val=val%(a[i]+b[i]);
            if(val>a[i]) s+=b[i]-(val-a[i]);
            else if(a[i]-val<cost[i]) s+=a[i]-val+b[i];
            if(s+cost[i]<dis[v])
            {
                dis[v]=s+cost[i];
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return dis[des];
}
int main()
{
  int cas=1;
  while(~scanf("%d%d%d%d",&n,&m,&s,&t))
  {
      memset(head,-1,sizeof(head));
      e=0;
      for(int i=0;i<m;i++)
      {
          int from,to,open,close,time;
          scanf("%d%d%d%d%d",&from,&to,&open,&close,&time);
          if(open>=time)addedge(from,to,time,open,close);
      }
      printf("Case %d: %d\n",cas++,spfa(s,t));
  }
}


/*赛车从进入直到出跑道，一直是打开状态。则d[v] = min(d[v], d[u] + t)
赛道已经关闭或会在中途关闭，则只能等到下次刚刚打开时进入，因此有个等待时间。d[v] = min(d[v], d[u] + wait + t)
*/
