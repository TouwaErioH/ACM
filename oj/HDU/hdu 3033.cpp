#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005
using namespace std;

int dp[105][N];  ///dp[k][i] 代表在前k组中花费i取得的最大价值
int a[105],price[105],value[105];
int main()
{
    int n,m,K;
    while(scanf("%d%d%d",&n,&m,&K)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&a[i],&price[i],&value[i]);
        }
        memset(dp,-1,sizeof(dp)); ///-1表示状态不合法
        for(int i=0; i<=m; i++) dp[0][i]=0;
        for(int k=1; k<=K; k++)
        {
            for(int i=1; i<=n; i++)
            {
                if(a[i]==k)                            //从第一种开始，更清晰
                    for(int v=m; v>=price[i]; v--)
                    {
                        if(dp[k][v-price[i]] != -1)
                            dp[k][v] = max(dp[k][v] , dp[k][v - price[i]] + value[i]);
                        if(dp[k-1][v-price[i]] != -1 )
                            dp[k][v] = max(dp[k][v] , dp[k-1][v-price[i]] + value[i]);
                    }
            }
        }
        if(dp[K][m]==-1) printf("Impossible\n");
        else printf("%d\n",dp[K][m]);
    }
    return 0;
}

/*
如果我们一开始把dp初始化为0，
则当所有鞋子的价值都是0时，
我们就无法区分是买不全那几款鞋子还是能买全但最
大价值是0
进行01背包.我们当前选第k组的时候在里面选择物品的时候是选的第几件.如果我们当前是选第k组中的第一件，
那么是从第k-1组推过来的,
如果不是取第一件(i)，那么就是第k组中的前一件(i-1)推过来的.
但是这里有个非常重要的问题，我们写成要写成如下形式两个if不能调转:
if(dp[k][v-price[i]] != -1)
        dp[k][v] = max(dp[k][v] , dp[k][v - price[i]] + value[i]);
if(dp[k-1][v-price[i]] != -1 )
        dp[k][v] = max(dp[k][v] , dp[k-1][v-price[i]] + value[i]);
解释：顺序不能调转，因为如果代价为0，调转的话，有可能出现先有dp[k][v] = dp[k-1][v-0]+v，再有dp[k][v] =dp[k][v-0]+v = dp[k-1][v-0]+v+v,所以物品取了两次.
*/
