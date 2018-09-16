#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[40005];
int dp[40005];

void solve(int n)
{
    fill(dp,dp+n,0x3f3f3f);
    for(int i = 0; i < n; i++)
            *lower_bound(dp,dp+n,a[i])=a[i];
        printf("%d\n",lower_bound(dp,dp+n,0x3f3f3f)-dp);
}


int main()
{
    int cas, n, ans;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
            solve(n);
    }
    return 0;
}
