#include<bits/stdc++.h>   //等效为只有一个人+-
using namespace std;
const int MAXN = 100005;
typedef long long LL;
int a[MAXN], b[MAXN];
bool cmp(int c,int d)
{
    return c>d;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    a[n]=b[n]=-1;
    sort(a, a + n,cmp);
    sort(b, b + n,cmp);
    int ax = 0, bx = 0;
    LL ans = 0;
    while(ax!=n||bx!=n) {
        if(a[ax] >= b[bx]) ans += a[ax++];
        else ++bx;
        if(a[ax] >= b[bx]) ++ax;
        else ans -= b[bx++];
    }
    cout << ans << endl;
}
