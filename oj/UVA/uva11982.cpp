/*
首先我们定义第一维状态是当前匹配到的点是谁。
然后我们容易发现对于S1 集合的 i 和 S2 集合的 i ，　当二分图处于完美匹配时，　S2 中的 i 及 i 以上的点中会有几个点不与S1 中 i 点以上的点匹配。　把这些边去掉之后这几个点就成为了未匹配点。

由此我们发现了子问题：i-1以上有j 个点未匹配时的总数。

于是我们定义状态的第二维：S2中i点以上未匹配点有j个

至此状态定义完毕。
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int length;
char s[maxn];
long long dp[maxn][maxn];
const long long mod = 1000000007;

void fdp(void){
 memset(dp,0,sizeof(dp));
 dp[0][0] = 1;
		for (int i = 1; i <= length; i++){
            if (s[i] == 'U'){
				for (int j = 0; j <= i; j++){
					if (j > 0)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j]*j%mod) % mod;
					else
                        dp[i][j] = (dp[i][j] + dp[i - 1][j]*j%mod) % mod;
				}
			}
			else if (s[i] == 'D'){
				for (int j = 0; j <= i; j++){
					dp[i][j] = (dp[i][j] + dp[i - 1][j] * j%mod +
						dp[i - 1][j + 1] * (j + 1) % mod*(j + 1) % mod) % mod;
				}
			}
			else{
				for (int j = 0; j <= i; j++)
					dp[i][j] = dp[i - 1][j];
			}
		}
}

int main(){
	int T,kase=0;
	cin >> T;
	while(T--){

		scanf("%s",s+1);
		length = strlen(s+1);
		fdp();
		printf("Case %d: %d\n",++kase,dp[length][0]);
	}
	return 0;
}
