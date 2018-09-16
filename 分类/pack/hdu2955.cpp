#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define maxn 10010//100*100+5
int m[105];
double dp[maxn],p[105];
int main(){
	int T,n;
	while(scanf("%d",&T)==1){
		while(T--){
			double P;
			memset(dp,0,sizeof(dp));
			memset(p,0,sizeof(p));
			memset(m,0,sizeof(m));
			scanf("%lf%d",&P,&n);
			P=1.0-P;
			int sum=0;
			for(int i=1;i<=n;i++)
            {
                scanf("%d%lf",&m[i],&p[i]);
                sum+=m[i],p[i]=1.0-p[i];
            }
			dp[0]=1.0;
			for(int i=1;i<=n;i++){
				for(int v=sum;v>=0;v--){
					if(v>=m[i]) dp[v]=max(dp[v],dp[v-m[i]]*p[i]);
				}
			}
			int ans=0;
			for(int v=sum;v>=0;v--){
				if(dp[v]-P>=eps){
					ans=v; break;
				}
			}
			printf("%d\n",ans);
		}
	}
}
