/*����Ҫ����ţ��ǮΪC
1���Ӵ���ֵ��С��ֵһ����Ǯ�����ö����ö��١�
����ע�ⲻ���õ���Ǯ���ܺʹ���C
2�������һ���õ���Ǯ����C����ô�ʹ�С��ֵ������ֵ��Ǯ�����ö����ö��١�
ֱ���õ���Ǯ�ܺʹ��ڵ���C
���õ���Ǯ������Ҫ����C�ܶ�������ŵģ����Եڶ���Ҫ��С������*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f
using namespace std;
int use[30];//��¼��ǰȡ���ĵ�i����ֵȡ�ĸ���
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
		for(i=n-1;i>=0;i--)//��һ�����������C����ֵȫ��ȡ��
		{
			if(a[i].first>=c)
			{
				ans+=a[i].second;
				a[i].second=0;
			}
		}
		while(1)//ÿ��ѭ��������һ�ε�ǰ����ȡ����ֱ��ʣ�µ��ܽ��С��CԪ
		{
			int flag=0;
			cnt=c;
			memset(use,0,sizeof(use));
			for(i=n-1;i>=0;--i)//�ڶ������Ӵ�Сȡ�����ܳ���C��ֵ
			{
				if(a[i].second)
				{
					k=cnt/a[i].first;
					m=min(k,a[i].second);   //���и�ֵ���֣�m=0������
					cnt-=m*a[i].first;
					use[i]=m;
					if(cnt==0)     //����Ҫ�ٲ�С��//�����Ѿ�����  ���������==0��ǡ�ã��Ϳ���������С�ģ��������Ҫ��С��
					{
						flag=1;
						break;
					}
				}
			}
		if(cnt>0)
			{
				for(i=0;i<n;++i)//����������С����ȡ������C
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
				if(use[i])//�ҵ���ǰȡ������ȡ���ܴ���
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
