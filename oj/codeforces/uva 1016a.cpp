#include<bits/stdc++.h>
using namespace std;
int a[200000+5];
int main()
{
	int n,m,sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		int t=sum/m;
		printf("%d ",t);
		sum=sum-t*m;
	}
	return 0;
 }
