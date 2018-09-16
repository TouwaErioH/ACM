#include <cstdio>
#include <cstring>
int const MAXM = 100005;
int const MAXN = 105;
bool dp[MAXM];
int cnt[MAXM];
int a[MAXN], c[MAXN];

int  main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF &&n)
    {
        memset(dp, false, sizeof(dp));
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &c[i]);
        dp[0] = true;
        int ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            memset(cnt, 0, sizeof(cnt));
            for(int s = a[i]; s <= m; s ++)
            {
                if(!dp[s] && dp[s - a[i]] && cnt[s - a[i]] < c[i])
                {
                    dp[s] = true;
                    ans ++;
                    cnt[s] = cnt[s - a[i]] + 1;
                }
            }
        }
        printf("%d\n", ans);
    }
}
