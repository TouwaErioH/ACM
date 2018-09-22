#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 4005;

int n;
int a[4][N];
int x[N*N], y[N*N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < 4; j ++)
            scanf("%d", &a[j][i]);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            x[i*n+j] = a[0][i] + a[1][j];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            y[i*n+j] = a[2][i] + a[3][j];
    sort(y, y+n*n);

    long long ans = 0;
    for (int i = 0; i < n*n; i ++)
        ans += (upper_bound(y, y+n*n, -x[i]) - lower_bound(y, y+n*n, -x[i]));
    printf("%lld\n", ans);

    return 0;
}
