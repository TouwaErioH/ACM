/*对于一颗树（子树），如果他的儿子数超过1，则需要改动，，
如果他有父亲节点，那么代价是（son-2）*2（先拆再连），将这颗子树变成一个链
如果这个点是root，代价是（son-1）*2，（画图脑补）
最后改完后再把首位一连（ans++）*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000010;
struct edge
{
        int to,next;
}e[maxn<<1];

int tot,head[maxn],n,num;

void init()
{
        tot=0;
        memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
        e[tot].to=v;
        e[tot].next=head[u];
        head[u]=tot++;
}
int dfs(int root,int fa)
{
        int t=0;
        for(int i=head[root];i!=-1;i=e[i].next)
        {
                int v=e[i].to;
                if(fa==v)       continue;
                t+=dfs(v,root);
        }
        if(t>1)
        {
                if(fa==-1)      num+=t-2;
                else num+=t-1;
                return 0;
        }
        return 1;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                init();
                num=0;
                for(int i=1;i<n;i++)
                {
                        int u,v;
                        scanf("%d%d",&u,&v);
                        addedge(u,v);
                        addedge(v,u);
                }
                int temp=dfs(1,-1);
                printf("%d\n",2*num+1);

        }
        return 0;
}
