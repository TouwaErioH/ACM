#include<cstdio>
#include<iostream>
#include<cstring>
int kase,n,r;
bool buy[25];
double p[25],sum[25];

void dfs(int d,int c,double prob)
{
    if(c>r||d-c>n-r+1) return;
    if(d==n+1)
    {
        sum[n+1]+=prob;
        for(int i=1;i<=n;i++)
            if(buy[i])
            sum[i]+=prob;
        return;
    }
    buy[d]=0;
    dfs(d+1,c,prob*(1-p[d]));
    buy[d]=1;
    dfs(d+1,c+1,prob*p[d]);
}
int main()
{
    while(scanf("%d%d",&n,&r)==2&&(n||r))
    {
        memset(sum,0,sizeof(sum));
        memset(buy,0,sizeof(buy));
        for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
        dfs(1,0,1.0);
        printf("Case %d:\n",++kase);
        for(int i=1;i<=n;i++)
            printf("%.6lf\n",sum[i]/sum[n+1]);
    }
    return 0;
}
