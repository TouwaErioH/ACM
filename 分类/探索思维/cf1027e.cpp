#include<bits/stdc++.h>
#define MAXN 510
#define MOD 998244353
using namespace std;
typedef long long ll;

int n,k;
ll dp[MAXN][MAXN],ret,ans[MAXN];
void solve (void){
 for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<=n;j++)
            for(int k=1;k<=min(j,i);k++)
                dp[i][j]=(dp[i][j]+dp[i][j-k])%MOD;  //不超过连续为i，长为j
    }
    for(int i=1;i<=n;i++)
        ans[i]=(dp[i][n]-dp[i-1][n]+MOD)%MOD;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i*j<k)
                ret=(ret+ans[i]*ans[j])%MOD;
                ret=(2ll*ret%MOD+MOD)%MOD;
}

int main(){
    scanf("%d%d",&n,&k);
    solve();
    printf("%I64d",ret);
}

/*我们可以把这个矩形的的每一行设一个值ai，每一列设定一个值bi。其中ai,bi=0或1

然后对于格子(i,j)
其颜色就是：ai xor bj。

无非就是a中最长的一段连续相同的值和b

中最长的一段连续相同的值的乘积不超过k

就可以用dp求出：对于最长连续相同长度刚好为x

的，总长度为n的01序列的方案数。

发现这个刚好为x其实不便表示，所以可以用一下差分的思想：求出最长长度不超过x的方案数，设为dpx
，然后我们要的就是dpx−dpx−1

。这样就排除了所有长度未达到x的方案。

然后这个dp就非常简单了
设dp(i,j)

表示前i个位置，最长连续相同不超过j的方案数。

然后dp(i,j)=∑k=1,k≤min(j,i)dp(i−k,j)
*/
