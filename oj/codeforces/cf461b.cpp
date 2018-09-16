#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int mod=1e9+7;
int n,color[100005];
vector <int> mp[100005];
long long dp[100005][2];
void dfs(int now)
{
    dp[now][0]=1;
    dp[now][1]=0;
    for(int i=0;i<mp[now].size();i++)
    {
        int to=mp[now][i];
        dfs(to);
        dp[now][1]=(dp[now][1]*dp[to][0]+dp[now][0]*dp[to][1])%mod;
        dp[now][0]=dp[now][0]*dp[to][0]%mod;
    }
    if(color[now]==1)
    dp[now][1]=dp[now][0];
    else
    dp[now][0]=(dp[now][0]+dp[now][1])%mod;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        mp[a].push_back(i);
    }
    for(int i=0;i<n;i++)
    scanf("%d",&color[i]);
    dfs(0);
    long long ans=dp[0][1];
    cout<<ans<<endl;
    return 0;
}
