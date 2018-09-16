#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long LL;

const int maxn=10000+5;

int n;

int primes[maxn];
LL sum[maxn];
int isprime[maxn];
int cnt;

void init()
{
    cnt=0;
    int m = sqrt(maxn + 0.5);
    for (int i = 2; i < m;i++)   //练一下优化的埃式筛法
    {
        if(!isprime[i])
        {
            for(int j=i*i;j<maxn;j+=i)
                isprime[j]=1;
        }
    }

    sum[0]=0;
    for(int i=2;i<=maxn;i++)
    {
        if(!isprime[i])
        {
            primes[++cnt]=i;
            sum[cnt]=sum[cnt-1]+i;
        }
    }
}


int main()
{

    init();
    while(cin>>n && n)
    {
        int ans=0;
        for(int i=1;i<=cnt;i++)
            for(int j=0;j<i;j++)
            if(sum[i]-sum[j]==n)
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}
