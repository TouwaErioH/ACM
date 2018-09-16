#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e6+4;
long long a[maxn];
long long c[maxn];
int main()
{
    int n;
    long long ave, sum;
    while(scanf("%d",&n)==1)
    {
        sum = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
            sum += a[i];
        }
        ave = sum / n;
        c[0] = 0;
        for(int i = 1; i < n; i++)
            c[i] = c[i-1] + a[i] - ave;
        sort(c, c+n);
        long long x1 = c[n/2], ans = 0;
        for(int i = 0; i < n; i++)
        ans += abs(x1 - c[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
