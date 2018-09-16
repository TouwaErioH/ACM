/*����һ��������������������Ķ���������1������Ҫ�Ķ�����
������и��׽ڵ㣬��ô�����ǣ�son-2��*2���Ȳ���������������������һ����
����������root�������ǣ�son-1��*2������ͼ�Բ���
��������ٰ���λһ����ans++��*/
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
