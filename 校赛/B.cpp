#include <iostream>
#include <cstdio>
#include <vector>
#define MOD 1000000007
int ans[1000003];

using namespace std;

//������

long long int quickpow(long long int a, long long int b)
{
	a %= MOD;//ÿ�ζ��ǵ�ȡģ
	//res���ڼ�¼���
	long long int res = 1;
	for (; b; b >>= 1)//b����һλ���������Ƕ�b�Ķ�������ÿһ�������б���
	{
		//b��1�������㣬�����Ͼ����ж�b�Ķ�������ʽ������λ�Ƿ�Ϊ1��������Ϊ1������Ϊ0
		if (b & 1)//���b�Ķ�����ĩλ��Ϊ0
		{
			res = (res*a) % MOD;
		}
		a = (a*a) % MOD;//ÿ�μ�¼����a������b��Ϊ0����µ�ֵ��������һ��ѭ�������
	}
	return res;
}

//����Ԫ

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
