/*
һ��ʼnc�ˣ�������ÿһվ�������͡�����*/
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
        cur = cur + (a[i] - a[i-1]) * two[n - i];    //����dp���۲췢�����*2^n-1��ֱ�ӳ���ȥ���ڷ���ÿ�����ӵ�
        //cur=2^n-2 * (a[I]+A[I-1) �� cur(i-1)+(a[i] - a[i-1]) * two[n - i]
        cur %= mod;
        ans = (ans + cur) % mod;
    }
    cout << (ans % mod + mod) % mod << endl;
}

�򵥵�˼·���ֱ�д��ÿһվ�ģ�ע��1����2ҪԤ����Ҫ��LL
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
