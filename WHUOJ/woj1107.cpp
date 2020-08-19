#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;

//dp[i][j]表示a串的i位匹配到b串的j位的最大代价，
//那么dp[i][j]=max(dp[i][j-1] + w[4][b[j]],dp[i-1][j] + w[4][a[i]],dp[i-1][j-1] + w[a[i]][b[j]])。




map<char,int>mapp={{'A',0},{'C',1},{'G',2},{'T',3},{'-',4}};
vector<int>value[5]={{5,-1,-2,-1,-3},
             {-1,5,-3,-2,-4},
			 {-2,-3,5,-2,-2},
			 {-1,-2,-2,5,-1},
			 {-3,-4,-2,-1,0}};

int getvalue(char d1,char d2){
	int a,b;
	a=mapp[d1];
	b=mapp[d2];
	return value[a][b];
}

int T,length1,length2;
int ans;
const int len=110;
char dna1[len],dna2[len];
int dp[len][len];

int mymax(int a,int b,int c){
    int maxn=a>b?a:b;
	return maxn>c?maxn:c;
}

int dpfunc(){
        dp[0][0]=0;
		for(int i=1;i<=length1;i++)
            dp[i][0]=getvalue(dna1[i-1],'-')+dp[i-1][0];
		for(int i=1;i<=length2;i++)
            dp[0][i]=getvalue('-',dna2[i-1])+dp[0][i-1];
		for(int i=1;i<=length1;i++)
		    for(int j=1;j<=length2;j++){
			dp[i][j]=mymax(dp[i-1][j-1]+getvalue(dna1[i-1],dna2[j-1]),dp[i][j-1]+getvalue('-',dna2[j-1]),dp[i-1][j]+getvalue('-',dna1[i-1]));
		}
        return dp[length1][length2];
}

int main(){
    cin>>T;
	while(T--){
		scanf("%d %s %d %s",&length1,&dna1,&length2,&dna2);  //空格
		ans=dpfunc();
		cout<<ans<<endl;
	}
	return  0;
}