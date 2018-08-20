#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=2005;

int n;
int a[N],b[N];
long long int dp[N][N];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		long long mn=dp[i-1][1];
		for(int j=1;j<=n;j++)
		{
			mn=min(mn,dp[i-1][j]);
			dp[i][j]=abs(a[i]-b[j])+mn;
		}
	}
	long long ans=dp[n][1];
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	solve();

	return 0;
}
