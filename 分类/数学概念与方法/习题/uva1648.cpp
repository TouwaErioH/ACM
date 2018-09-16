#include <iostream>
#include <cstdio>
#include<cmath>
using namespace std;
int bsearch(int n, int u, int d) {
    int left = 0, right= n;
    int ans = 0x3f3f3f3f;
    while(left <= right) {
        int m = (left + right)/2;
        if(m * (u + d) - n * d > 0)
        {
            ans = m * (u + d) - n * d;
            right = m - 1;
        }
        else left = m + 1;
    }
    return ans;
}
int main() {
    int n, m, u, d, i;
    while(scanf("%d%d", &n, &m)==2) {
        int ans = 0x3f3f3f3f;
        while(m--) {
            scanf("%d%d", &u, &d);
            ans=min(ans,bsearch(n, u, d));
        }
        printf("%d\n", ans);
    }
    return 0;
}

