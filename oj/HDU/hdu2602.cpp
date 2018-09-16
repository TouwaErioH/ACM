#include<iostream>
#include <algorithm>
#include<cstring>
using namespace std;
int dp[1005][1005];

int main()
{
    int t,n,v,i,j;
    int va[1000],vo[1000];
    cin>>t;
    while(t--)
    {
        cin>>n>>v;
        for(i=1;i<=n;i++)
            cin>>va[i];
        for(i=1;i<=n;i++)
            cin>>vo[i];
        memset(dp,0,sizeof(dp));
         for(i=1;i<=n;i++)
        {
            for(j=0;j<=v;j++)
            {
                if(j<vo[i])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vo[i]]+va[i]);
            }
        }
        cout<<dp[n][v]<<endl;
    }
    return 0;
}
