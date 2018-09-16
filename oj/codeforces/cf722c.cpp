#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 100005;
using namespace std;
LL pre[MAXN], cnt[MAXN], a[MAXN], pos[MAXN], visit[MAXN];
unsigned long long ans[MAXN];

int findpar(int x)
{
    return x == pre[x] ? x : pre[x] = findpar(pre[x]);
}

void unite(int x, int y) {
    int fx = findpar(x), fy = findpar(y);
    if(fx != fy) pre[fy] = fx, cnt[fx] += cnt[fy]; //合并两个集合的同时维护新集合的 sum
}

int main() {
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = i, visit[i] = 0;
    }
    for(int i = 0; i < n; i++)
        cin >> pos[i];
    LL maxn = 0;
    for(int i = n - 1; i >= 0; i--) {
        int tp = pos[i];
        cnt[tp] = a[tp], visit[tp] = 1, ans[i] = maxn;
        if(tp != 1 && visit[tp - 1])
            unite(tp, tp - 1); // 新增一个元素后形成的四种情况
        if(tp != n && visit[tp + 1])
            unite(tp, tp + 1);
        maxn = max(maxn, cnt[findpar(tp)]);
    }
    for(int i = 0; i < n; i++)
        printf("%lld\n",ans[i]);
    return 0;
}
