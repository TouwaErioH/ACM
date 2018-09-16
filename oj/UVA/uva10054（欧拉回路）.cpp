#include <cstdio>
#include <cstring>
#define N 55
#define MAX 1010
int g[N][N];
int d[N];
int n;

void euler(int u)
{
    int v;
    for(v=1; v<=50; v++)
        if(g[u][v])
        {
            g[u][v]--;
            g[v][u]--;
            euler(v);
            printf("%d %d\n",v,u);
            //一定要逆序输出
        }
}
int main()
{
    int t,T;
    int i,j;
    int u,v;
    scanf("%d",&T);
    for(t=1 ;t<=T; t++)
    {
        memset(g,0,sizeof(g));
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(i=1 ;i<=n; i++)
        {
            scanf("%d%d",&u,&v);
            d[u]++;
            d[v]++;
            g[u][v]++;
            g[v][u]++;
        }
        printf("Case #%d\n",t);
        for(i=1 ;i<=50; i++)
            if( d[i]%2 )
                break;
        if(i<=50)
            printf("some beads may be lost\n");
        else
                euler(u);

        if(t!=T) printf("\n");
    }
    return 0;
}
