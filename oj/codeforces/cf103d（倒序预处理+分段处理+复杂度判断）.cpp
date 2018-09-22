#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300005;
const int MAXM = (sqrt(MAXN+0.5) + 2);
int n, w[MAXN], p, m;
LL sum[MAXN], ans[MAXN];

struct questions {
    int a, b, id;
    bool operator < (const questions& r) const {
        return b < r.b;
    }
}q[MAXN];

void solve(int j) {
    for(int i = n; i >= 1; --i) {  //倒序预处理
        sum[i] = w[i];
        if(i + j <= n)
            sum[i] += sum[i+j];
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", w + i);
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        q[i] = questions{a, b, i};
    }
    sort(q + 1, q + m + 1);
    int curb = -1;
    for(int i = 1; i <= m; ++i) {
        int a = q[i].a, b = q[i].b;
        if(b < MAXM) {
            if(b!=curb) solve(b);
            curb = b;
            ans[q[i].id] = sum[a];
        }
        else {                           //分段，计算量小的直接算
            LL ret = 0;
            for(int i = a; i <= n; i += b) ret += w[i];
            ans[q[i].id] = ret;
        }
    }
    for(int i = 1; i <= m; ++i)
        printf("%lld\n", ans[i]);
}
