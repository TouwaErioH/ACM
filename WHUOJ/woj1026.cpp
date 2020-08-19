
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int mymax(int a,int b,int c){
	int max=a>b?a:b;
	max=max>c?max:c;
	return max;
}

int t,ti,n,i,j,ans=0;
const int N=1010;
int mapp[N][N];
int dp[N][N];

int main(){

	cin>>t;
    int flag=0;
    int cnt=0;
	while(t--){
		cin>>n;
        cnt++;
		for(i=1;i<=n;i++)
		    for(j=1;j<=n;j++)
                dp[i][j]=0;

		for(i=1;i<=n;i++)
		    for(j=1;j<=n;j++)
			cin>>mapp[i][j];

		for(j=1;j<=n;j++)
            dp[1][j]=mapp[1][j];
		for(i=2;i<=n;i++)
		    for(j=1;j<=n;j++)
		        dp[i][j]=mymax(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+mapp[i][j];
		for(j=1;j<=n;j++)
		    if(ans<dp[n][j])
                ans=dp[n][j]; 

		if(flag)
		puts("");
        flag=1;
		printf("Case %d:\n",cnt);

		cout<<ans<<endl;	
	}
	return 0;
}