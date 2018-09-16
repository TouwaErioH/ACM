#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100100;
double dp[maxn];
void init()
{
    dp[2]=1.0;
    for(int i=4;i<maxn;i+=2)
        dp[i]=dp[i-2]*(i-3)/(i-2);
}
int main()
{
    int n,x;
    init();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        printf("%.4f\n",1.0-dp[x]);
    }
}
