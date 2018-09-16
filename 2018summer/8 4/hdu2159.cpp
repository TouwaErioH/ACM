#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=110;
int dp[maxn][maxn];
int rn[maxn],ex[maxn];
int n,m,k,s,ans;

int main()
{
    while (scanf("%d%d%d%d",&n,&m,&k,&s)==4) {
        memset (dp,0,sizeof (dp));
        for (int i=0;i<k;i++)
            scanf("%d%d",&ex[i],&rn[i]);
        ans=-1;
        for (int i=0;i<k;i++) {
            for (int tem=rn[i];tem<=m;tem++) {
                for (int l=1;l<=s;l++) {
                    dp[l][tem]=max(dp[l][tem],dp[l-1][tem-rn[i]]+ex[i]);
                    if (dp[l][tem]>=n&&(m-tem)>ans)
                        ans=m-tem;
                }
            }
        }
            printf("%d\n",ans);

    }
    return 0;
}
/*
dp[i][j] 表示在杀i个怪物，在忍耐度j的范围内，获取的最大经验
dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
*/
