#include <bits/stdc++.h>
using namespace std;
const long long N=1000+20;
const long long mod=1e9+7;
long long pow_mod(long long a,long long b,long long mo)
{
    long long ans=1;
    a%=mo;
    while(b)
    {
        if(b&1)
            ans=ans*a%mo;
        a=a*a%mo;
        b>>=1;
    }
    return ans;
}
int main()
{
    long long n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k==-1&&(n+m)&1)
        puts("0");
    else
        printf("%lld\n",pow_mod(pow_mod(2,n-1,mod),m-1,mod));
    return 0;
}
