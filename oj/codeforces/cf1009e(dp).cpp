/*
一开始nc了，计算了每一站的期望和。。。*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000100;
const int mod = 998244353;
LL two[MAXN];
int a[MAXN];
void init() {
    two[0] = 1;
    for(int i = 1; i < MAXN; ++i) two[i] = two[i-1] * 2 % mod;

}
int main() {
    init();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    LL ans = two[n-1] * a[1] % mod;
    LL cur = ans;
    for(int i = 2; i <= n; ++i) {
        cur = cur + (a[i] - a[i-1]) * two[n - i];    //类似dp；观察发现最后*2^n-1，直接乘上去；在发现每次增加的
        //cur=2^n-2 * (a[I]+A[I-1) 即 cur(i-1)+(a[i] - a[i-1]) * two[n - i]
        cur %= mod;
        ans = (ans + cur) % mod;
    }
    cout << (ans % mod + mod) % mod << endl;
}

简单的思路，分别写出每一站的；注意1《《2要预处理；要用LL
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;
const int maxn = 1e6 + 7;
int n;
ll ans;
ll a[maxn], p[maxn];

int main() {
    scanf("%d", &n);
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] * 2 % mod;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
    }
    ans = a[n];
    for(int i = 1; i < n; i++) {
        ans = (ans + (a[i] * (p[n - i] + p[n - i - 1] * (n - i) % mod) % mod) % mod) % mod;
    }
    printf("%I64d\n", ans);
    return 0;
}

*/
