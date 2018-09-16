#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100+5;
#define INF 1e8

int n;
int t;
int dp[maxn][maxn];
int cost[maxn];
int val[maxn];

int main()
{
    while(scanf("%d%d",&n,&t)==2)
    {
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++)
        {
            int m,s;
            scanf("%d%d",&m,&s);
            for(int k=1;k<=m;k++)
                scanf("%d%d",&cost[k],&val[k]);

            if(s==0)//至少选1个的01背包问题
            {
                for(int j=0;j<=t;j++) dp[i][j]=-INF;

                for(int k=1;k<=m;k++)
                for(int j=t;j>=cost[k];j--)
                {
                    dp[i][j] = max( dp[i][j] , dp[i][j-cost[k]]+val[k] );  //1
                    dp[i][j] = max( dp[i][j] , dp[i-1][j-cost[k]]+val[k] );//2
                    //上面两句顺序互换就会出错!为什么?
                }
            }
            else if(s==1)//至多选1个的背包问题
            {
                for(int j=0;j<=t;j++) dp[i][j]=dp[i-1][j];

                for(int k=1;k<=m;k++)
                for(int j=t;j>=cost[k];j--)//j可以正序或逆序枚举
                    dp[i][j] = max( dp[i][j] , dp[i-1][j-cost[k]]+val[k] );
            }
            else if(s==2)//随便选的01背包问题
            {
                for(int j=0;j<=t;j++) dp[i][j]=dp[i-1][j];

                for(int k=1;k<=m;k++)
                for(int j=t;j>=cost[k];j--)//j只能逆序枚举
                    dp[i][j] = max( dp[i][j] , dp[i][j-cost[k]]+val[k] );
            }
        }

        int ans = max(dp[n][t],-1);
        printf("%d\n",ans);
    }
    return 0;
}
