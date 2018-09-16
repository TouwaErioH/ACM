#include<cstring>
#include<iostream>
#include<cstdio>
#include <algorithm>
#define M 100005
using namespace std;
int dp[M],pp[M];
int a[105],b[105],c[105];
int n,k;
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset(dp,-0x3f ,sizeof(dp));
        memset(pp,-0x3f ,sizeof(pp));
        dp[0]=pp[0]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            c[i]=a[i]-b[i]*k;
        }
        for(int i=0;i<n;i++)
        {
            if(c[i]>=0)
            {
               for(int j=100000;j>=c[i];j--)
               {
                   dp[j]=max(dp[j],dp[j-c[i]]+a[i]); //如果追溯不到0，会是很小的值
               }
            }
            else
            {
                c[i]=-c[i];
                  for(int j=100000;j>=c[i];j--)
               {
                   pp[j]=max(pp[j],pp[j-c[i]]+a[i]);
               }

            }
        }
        int ans=-1;
        for(int i=0;i<=100000;i++)
        {
            if(dp[i]==0&&pp[i]==0)
                continue;
            else
                ans=max(dp[i]+pp[i],ans);
        }
        cout<<ans<<endl;
        }
    }
