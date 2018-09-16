#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;
const int  maxn = 20000+10;
int a[maxn];
int b[maxn];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];
		int cost=0;
		sort(a,a+n);
		sort(b,b+m);
		int cur=0;
		for(int i=0;i<m;i++)
		{
			if(b[i]>=a[cur])
			{
				cost=cost+b[i];
				if(++cur==n) break;
			}
		}
		if(cur<n)
		  printf("Loowater is doomed!\n");
		else
		 cout<<cost<<endl;
	}
	return 0;
}
