#include <bits/stdc++.h>

using namespace std;

int n;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

void handle(long long &zi,long long &mu)
{
	long long yin=gcd(zi,mu);
	if(yin!=0) zi/=yin,mu/=yin;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		long long zi=0,mu=1;
		long long sum=1;
		for(int i=1;i<n;i++)
		{
			sum=sum+n/(n-i);
			if(n%(n-i))
			{
				zi=zi*(n-i)+n%(n-i)*mu;
				mu*=(n-i);
				handle(zi,mu);
				if(mu==1)
				{
					sum+=zi;
					zi=0;
				}
				else
				{
					if(zi>mu)
					{
						sum+=(zi/mu);
						zi%=mu;
					}
				}
			}
		}
		if(mu==1) printf("%lld\n",sum);
		else
		{
			int cnt_m=1,cnt_i=1;
			int i=10;
			while(1)
			{
				if(mu/i!=0) cnt_m++;
				else break;
				i*=10;
			}
			i=10;
			while(1)
			{
				if(sum/i!=0) cnt_i++;
				else break;
				i*=10;
			}
			for(i=0;i<=cnt_i;i++) printf(" ");
			printf("%lld\n",zi);
			printf("%lld ",sum);
			for(i=0;i<cnt_m;i++) printf("-");
			printf("\n");
			for(i=0;i<=cnt_i;i++) printf(" ");
			printf("%lld\n",mu);
		}
	}
	return 0;
}
