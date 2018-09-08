#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int euler_phi(int n)
{
    int m=(int)(sqrt(n)+0.5);
    int ans=n;
    for(int i=2;i<=m;i++)
    if(n%i==0)
    {
        ans=ans/i*(i-1);
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        ans=ans/n*(n-1);
    return ans;
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int a,b;
    while(cin>>a>>b&&a)
    {
    long long ans = 0;
    for(int x = 1; x <= a; x++) {
    int k = b/x;
    ans +=euler_phi(x) * k;
    for(int y = k*x+1; y <= b; y++)
      if(gcd(x, y) == 1) ans++;
    }
   ans=ans * 4 + 4;
   long long tot=( long long)(2*a+1)*(2*b+1)-1;
   cout<<tot<<endl;
   long long tott=( long long)((2*a+1)*(2*b+1)-1);//这样加了括号先溢出了
   cout<<tott<<endl;
   printf("%.7lf\n",(double)ans/tot);
    }
    return 0;

}
