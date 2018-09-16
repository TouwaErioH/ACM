#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXV 410
#define MAXM 40010

struct Blocks{
	int h,a,c;
}v[MAXV];

int cmp(Blocks x,Blocks y){
	return x.a<y.a;
}
int dp[MAXM],used[MAXM];

int main(){
	int i,k,j,ans;
	while(scanf("%d",&k)==1){
		for(i=1;i<=k;i++){
			scanf("%d%d%d",&v[i].h,&v[i].a,&v[i].c);
		}
		sort(v+1,v+k+1,cmp);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		ans=0;
		for(i=1;i<=k;i++){
			memset(used,0,sizeof(used));
			for (j=v[i].h;j<=v[i].a;j++){
				if(!dp[j] && dp[j-v[i].h] &&(used[j-v[i].h]+1)<=v[i].c){
					dp[j]=1;
					used[j]=used[j-v[i].h]+1;
					if(j>ans) ans=j;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
