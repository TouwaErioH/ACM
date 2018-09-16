#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50000;
ll n,m,vis[maxn+5]={0},prime[maxn+5],cnt=0;

void init() {
    int m = sqrt(maxn);
    for(int i=2;i<=m;i++) if(!vis[i])
        for(int j=i*i;j<=maxn;j+=i) vis[j] = 1;
    for(int i=2;i<=maxn;i++)
        if(!vis[i]) prime[cnt++] = i;

}
ll gcd(ll a,ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
ll solve(ll n) {
    bool ok = false;
    ll ans = 0,temp = n;
    for(int i=0;i<cnt;i++) {
        ll c = 0;
        while(n % prime[i] == 0) {
            n /= prime[i];
            c++;
        }
        ans = gcd(ans,c);
        if(n == 1) break;
    }
    if(ans == 0) ans = 1;
    if(temp < 0)
        while(ans % 2 == 0) ans /= 2;
    return ans;
}
int main() {
    init();
    while(scanf("%lld",&n)&&n) {
        ll ans = solve(n);
        printf("%lld\n",ans);
    }
    return 0;
}
