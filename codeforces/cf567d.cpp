#include <iostream>
#include <algorithm>
#include <set>
using namespace std;//思路，每个船a+1(最后不一定)，x的区间，最多x+1/(a+1)个船
set<int> s;

int main()
{
    int m, n, a, k, x;
    while (scanf("%d%d%d", &n, &k, &a) != EOF) {
        scanf("%d", &m);
        s.clear();
        s.insert(0), s.insert(n+1);   // 实现虚拟长度的小技巧
        int sum = (n+1) / (a+1);
        int ans = -1, f = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            set<int>::iterator it = s.upper_bound(x);
            int r = *it;                //某个
            int l = *(--it);            //某个x
            sum = sum - (r-l)/(a+1) +(x-l)/(a+1) + (r-x)/(a+1);

            if (sum < k && !f) {
                ans = i;
                f = 1;
            }
            if(f)
                break;
            s.insert(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
