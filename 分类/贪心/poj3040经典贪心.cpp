/*假设要给奶牛的钱为C
1）从大面值到小面值一次拿钱，能拿多少拿多少。
但是注意不能拿到的钱的总和大于C
2）如果第一步拿到的钱不够C，那么就从小面值到大面值拿钱，能拿多少拿多少。
直到拿到的钱总和大于等于C
大拿到的钱尽量不要超过C很多才是最优的，所以第二步要从小到大拿*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f
using namespace std;
int use[30];//记录当前取法的第i种面值取的个数
pair<int,int>a[25];
int main()
{
	int n,c,i,cnt,ans,k,m;
	while(scanf("%d%d",&n,&c)==2)
	{
		for(i=0;i<n;++i)
			scanf("%d%d",&a[i].first,&a[i].second);
		sort(a,a+n);
		ans=0;
		for(i=n-1;i>=0;i--)//第一步，满足大于C的面值全部取走
		{
			if(a[i].first>=c)
			{
				ans+=a[i].second;
				a[i].second=0;
			}
		}
		while(1)//每次循环都在找一次当前最优取法，直到剩下的总金额小于C元
		{
			int flag=0;
			cnt=c;
			memset(use,0,sizeof(use));
			for(i=n-1;i>=0;--i)//第二步，从大到小取，不能超过C的值
			{
				if(a[i].second)
				{
					k=cnt/a[i].first;
					m=min(k,a[i].second);   //当有负值出现，m=0，不减
					cnt-=m*a[i].first;
					use[i]=m;
					if(cnt==0)     //不需要再补小的//或者已经补了  这个必须是==0，恰好，就可以跳过补小的；否则就需要补小的
					{
						flag=1;
						break;
					}
				}
			}
		if(cnt>0)
			{
				for(i=0;i<n;++i)//第三步，从小到大取，凑满C
				{
					if(a[i].second>use[i])
					{
						while(use[i]<a[i].second)
						{
							cnt-=a[i].first;
							use[i]++;
							if(cnt<=0)
							{
								flag=1;
								break;
							}
						}
					}
					if(flag)
						break;
				}
			}
			if(!flag)
				break;
			m=INF;
			for(i=0;i<n;++i)
			{
				if(use[i])//找到当前取法的能取的总次数
					m=min(m,a[i].second/use[i]);
			}
			ans+=m;
			for(i=0;i<n;++i)
			{
				if(use[i])
					a[i].second-=m*use[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
