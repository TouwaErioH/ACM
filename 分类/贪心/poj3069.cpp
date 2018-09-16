#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010];
int main()
{
	int n,R,i,ans;
	while(scanf("%d%d",&R,&n)&&R!=-1||n!=-1)
	{
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		i=0;ans=0;
		while(i<n)
		{
			int s=a[i++];
			while(i<n&&a[i]<=s+R)
				i++;
			int p=a[i-1];
			while(i<n&&a[i]<=p+R)
				i++;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
