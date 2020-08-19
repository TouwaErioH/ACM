#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=10005;
int dp[2][maxn];

int length1,length2;
string s1,s2;
int main() {
	while(cin>>s1>>s2) {
		length1=s1.size(),length2=s2.size();
        memset(dp,0,sizeof(dp));
		for (int i=1; i<=length2; i++) {
			for (int j=1; j<=length1; j++) {
				if (s2[i-1] == s1[j-1]) 
                    dp[i%2][j] = dp[(i+1)%2][j-1]+1;
				else 
                    dp[i%2][j] = (dp[i%2][j-1]<dp[(i+1)%2][j])?dp[(i+1)%2][j]:dp[i%2][j-1];
			}
		}
        cout<<dp[length2%2][length1]<<endl;
	}
	return 0;
}