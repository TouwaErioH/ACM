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

bool judge(int x) {  //������ֻ��1W������ʵ����p�ǿ��ܳ���1W�ģ�����������ֵֻ������һ��(��Ȼp*p������������)����˱���ö�����Ժ����һ������Ҫ�����жϣ��ж��Ƿ����������Ƿ���֮ǰ���õ���
    for (int i = 0; i < pn && prime[i] * prime[i] <= x; i++)
	if (x % prime[i] == 0) return false;     //������
    for (int i = 0; i < fn; i++) {
	if (vis[i] && f[i] == x) return false;  //vis�ı���   //primeֻ��1w������������һ��ֻ��Ҫ�ж�һ���Ƿ����������Ƿ�֮ǰ���ù���
    }                                   //��Ϊ��������m��Ȼ���Ա�ǰ���prime�� ����dfsʱ���Ĵ�������
    return true;
}

void dfs(int now, int sum, int tot) {   //sum �� phi/(prime-1)

    if (now == fn) {   //��������
	if (sum == 1) ans= min(ans, tot);   //tot ��prime�Ļ�
	else if (judge(sum + 1)) {
		tot *= (sum + 1);
	    ans = min(ans, tot);
	}
	return;
    }


    dfs(now + 1, sum, tot);
    if (sum % (f[now] - 1)) return;  //������


    vis[now] = 1;           //ʹ�����prime
    sum /= (f[now] - 1);
    tot *= f[now];          //n��primeֻ��һ�η�
    dfs(now + 1, sum, tot);

    while (sum % f[now] == 0) {   //m=n*(p1-1)/p1*....../=һ���൱��n��prime��ָ����һ
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
