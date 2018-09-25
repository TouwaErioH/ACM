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
        ans=0;double cnt=0;double p;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",p);

            ans+=(2*cnt+1)*p;
            cnt=(cnt+1)*p;
        }


        printf("%.15lf\n",ans);
    }
    return 0;
}
