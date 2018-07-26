#include <iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int v[maxn];
long long t[maxn];
long long sum[maxn];
int n;
priority_queue<long long ,vector<long long >,greater<long long > >q;
int main()
{
      while(cin>>n)
    {
        memset(t,0,sizeof(t));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
        }
         for(int i=1;i<=n;i++)
        {
            scanf("%d",&t[i]);
            sum[i]=sum[i-1]+t[i];
        }
        for(int i=1;i<=n;i++)
        {
            long long ans=0;
            q.push(v[i]+sum[i-1]);
            while(!q.empty()&&q.top()<=sum[i]) //�ų����б���ȫ�ڻ���ѩ
            {
                ans+=q.top()-sum[i-1];       //����i���岻ͬ����+��-�õ������ڵ�iʱ����ʣ��ѩ
                q.pop();
            }

            ans+=q.size()*t[i];
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}
