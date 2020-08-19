#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;



long long quickpow(long long a,long long b,long long c){
    long long ans = 1;
    long long base = a%c;
    while(b){
        if(b & 1) ans = (ans*base)%c;
        base = (base*base)%c;
        b >>= 1;
    }
    return ans;
}

long long a,b,c;

int main()
{

    while(scanf("%lld%lld%lld",&a,&b,&c))  //cin>>超时
    {
        if(a==0&&b==0&&c==0)
            break;
        printf("%lld\n",quickpow(a,b,c));
    }
    return 0;
}