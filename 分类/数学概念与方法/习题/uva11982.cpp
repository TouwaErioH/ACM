/*
�������Ƕ����һά״̬�ǵ�ǰƥ�䵽�ĵ���˭��
Ȼ���������׷��ֶ���S1 ���ϵ� i �� S2 ���ϵ� i ����������ͼ��������ƥ��ʱ����S2 �е� i �� i ���ϵĵ��л��м����㲻��S1 �� i �����ϵĵ�ƥ�䡣������Щ��ȥ��֮���⼸����ͳ�Ϊ��δƥ��㡣

�ɴ����Ƿ����������⣺i-1������j ����δƥ��ʱ��������

�������Ƕ���״̬�ĵڶ�ά��S2��i������δƥ�����j��

����״̬������ϡ�
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
