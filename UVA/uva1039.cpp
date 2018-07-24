#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define N 55
#define M 255
#define inf 999999
#define eps 1e-6
int mp[M][M],n,m;
struct Point{
double x,y;}city[M],bts[N];

void floyd()
{
        for(int k=0; k<=m; k++)
            for(int i=0; i<=m; i++)
                for(int j=0; j<=m; j++)
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
}

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int area(double x1,double y1)
{
    double d=999999999;
    int key;
    for(int i=1;i<=n;i++)
    {
        double tmp=dis(x1,y1,bts[i].x,bts[i].y);
        if (tmp<d)
        {
            d=tmp;
            key=i;
        }
    }
    return key;
}
int get_switch(double x1,double y1,double x2,double y2)
{
    if(area(x1,y1)==area(x2,y2)) return 0;
    if(fabs(dis(x1,y1,x2,y2))<eps) return 1;
    return get_switch(x1,x2,(x1+x2)/2,(y1+y2)/2)+get_switch((x1+x2)/2,(y1+y2)/2,x2,y2);
}

int main()
{
    int r,q,u,v,cas=1;
    while(scanf("%d%d%d%d",&n,&m,&r,&q)!=EOF)
    {
        if(n==0&&m==0&&r==0&q==0) break;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
            mp[i][j]=inf;
         for(int i=1;i<=n;i++)
            scanf("%lf%lf",&bts[i].x,&bts[i].y);
            for(int i=1;i<=m;i++)
            scanf("%lf%lf",&city[i].x,&city[i].y);
            for(int i=1;i<=r;i++)
         {
             scanf("%d%d",&u,&v);
             mp[u][v]=mp[v][u]=get_switch(city[u].x,city[u].y,city[v].x,city[v].y);
         }
         floyd();
         printf("Case %d:\n",cas++);
         for(int i=1;i<=q;i++)
         {
              scanf("%d%d",&u,&v);
              if(mp[u][v]==inf)
                printf("Impossible\n");
                else
                printf("&d\n",mp[u][v]);
         }
    }
    return 0;
}
