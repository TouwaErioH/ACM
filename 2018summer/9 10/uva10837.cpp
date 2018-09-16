/*
m=n*(p1-1)/p1*......   m/(p1-1) =n/p1 *...  _>  m/(p1-1)/p1= n/p1/p1 *...
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10005;
int pn, n, f[N], fn, ans=0x3f3f3f3f;
const int maxp=100005;
int prime[100000];
bool vis[100010];

void get_prime()
{
    int i,j;
    for (i=2;i<=maxp;i++)
    {
        if (!vis[i]) prime[pn++]=i;
        for (j=0;j<pn&&i*prime[j]<=maxp;j++)
        {
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}



void build(int n) {
    fn = 0;
    ans = 200000000;
    for (int i = 0; i < pn && (prime[i] - 1) * (prime[i] - 1) <= n; i++) {
	if (n % (prime[i] - 1)) continue;
	f[fn++] = prime[i];
    }
}

bool judge(int x) {  //素数表只打到1W，所以实际上p是可能超过1W的，但是这样的值只可能有一个(不然p*p都超过上限了)，因此暴力枚举完以后最后一个素数要单独判断，判断是否是素数与是否在之前被用掉了
    for (int i = 0; i < pn && prime[i] * prime[i] <= x; i++)
	if (x % prime[i] == 0) return false;     //是质数
    for (int i = 0; i < fn; i++) {
	if (vis[i] && f[i] == x) return false;  //vis改变了   //prime只打到1w；最后，如果超过一万只需要判断一次是否是素数；是否之前被用过；
    }                                   //因为可能最后的m仍然可以被前面的prime除 即做dfs时除的次数不够
    return true;
}

void dfs(int now, int sum, int tot) {   //sum 是 phi/(prime-1)

    if (now == fn) {   //遍历结束
	if (sum == 1) ans= min(ans, tot);   //tot 是prime的积
	else if (judge(sum + 1)) {
		tot *= (sum + 1);
	    ans = min(ans, tot);
	}
	return;
    }


    dfs(now + 1, sum, tot);
    if (sum % (f[now] - 1)) return;  //不整除


    vis[now] = 1;           //使用这个prime
    sum /= (f[now] - 1);
    tot *= f[now];          //n中prime只有一次方
    dfs(now + 1, sum, tot);

    while (sum % f[now] == 0) {   //m=n*(p1-1)/p1*....../=一次相当于n中prime的指数加一
	sum /= f[now];
	tot *= f[now];
	dfs(now + 1, sum, tot);
    }

    vis[now] = 0;
}

int main() {
    get_prime();
    int cas = 0;
    while (~scanf("%d", &n) && n) {
	build(n);
	memset(vis, 0, sizeof(vis));
	dfs(0, n, 1);
	printf("Case %d: %d %d\n", ++cas, n, ans);
    }
    return 0;
}
