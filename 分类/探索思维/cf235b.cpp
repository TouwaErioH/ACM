#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int n;

double dp[maxn],p[maxn];
double ans;
int main()
{
    while(scanf("%d",&n)==1)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",p+i);
            ans+=p[i];
        }
        dp[0]=0;
        int i=1;
        for(i;i<=n;i++)
        {
            dp[i]=p[i]*(dp[i-1]+1);
            ans+=2*(dp[i]-p[i]);
         }

        printf("%.15lf\n",ans);
    }
    return 0;
}
