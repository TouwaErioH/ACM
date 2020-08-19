
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

int candies[10005][3];
int judge[3][3];

int n,sum;
int ans;
int tp;
const int inf=0x7fffffff;

void solve(int a,int b){
	int i,mymax=0;
	for(i=0;i<n;i++){
		if(b==2){
			if(i==judge[a][0]||i==judge[a][1])
			continue;
		}
		if(b==1){
			if(i==judge[a][0])
			continue;
		}
		if(mymax<candies[i][a]){
			mymax=candies[i][a];
			judge[a][b]=i;
		}
	}
	return ;
}

int main(){

	while(cin>>n){
		sum=0;
        ans=inf;
		for(int i=0;i<n;i++){
			cin>>candies[i][0]>>candies[i][1]>>candies[i][2];
			sum+=candies[i][0];
			sum+=candies[i][1];
			sum+=candies[i][2];
		}
		for(int i=0;i<3;i++)
		    for(int j=0;j<3;j++)
		        solve(i,j);	
		for(int i=0;i<3;i++)
		    for(int j=0;j<3;j++)
		        for(int k=0;k<3;k++){
			        if(judge[0][i]==judge[2][k]||judge[0][i]==judge[1][j]||judge[1][j]==judge[2][k])
			            continue;
			        tp=sum-candies[judge[0][i]][0];
					tp=tp-candies[judge[1][j]][1];
					tp=tp-candies[judge[2][k]][2];
                    ans=ans>tp?tp:ans;
		}
		cout<<ans<<endl;
    }
        return 0;
}