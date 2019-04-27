#include <iostream>
#include <cstdio>
#include <vector>
#define MOD 1000000007
int ans[1000003];

using namespace std;

//快速幂

long long int quickpow(long long int a, long long int b)
{
	a %= MOD;//每次都记得取模
	//res用于记录结果
	long long int res = 1;
	for (; b; b >>= 1)//b右移一位，本质上是对b的二进制数每一个数进行遍历
	{
		//b和1做与运算，本质上就是判断b的二进制形式上最右位是否为1，是则结果为1，否则为0
		if (b & 1)//如果b的二进制末位不为0
		{
			res = (res*a) % MOD;
		}
		a = (a*a) % MOD;//每次记录本次a因子中b不为0情况下的值，用于下一次循环的求解
	}
	return res;
}

//求逆元

long long int inv(long long int a, long long int b)
{
	return quickpow(a, b - 2);
}

int main()
{
    int t;
	long long int n, i;
	ans[0] = 0; ans[1] = 1;
	for (i = 2; i <= 1000000; i++)
	{
		ans[i] = ans[i - 1] * (4 * i - 2) % MOD*inv(i + 1, MOD) % MOD;
	}
	while(scanf("%lld",&t)!=EOF)
	{
	    for(int i=1;i<=t;i++)
	    {int a,b;
	    cin>>a;cin>>b;
		printf("%d\n", ans[a]);
	    }
	}

	return 0;
}
