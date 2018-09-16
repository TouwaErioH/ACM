#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int ans[30*30];

int main(){
	int n, m, kase = 1;
	while(scanf("%d%d",&n,&m)==2&&n&&m){
            memset(ans,0,sizeof(ans));
		int i,flag=1;
		for(i = 1; i<=n*m; i++)
            scanf("%d",&ans[i]);
		sort(ans+1,ans+1+n*m);
		double sum, cnt = 0.0;
		scanf("%lf",&sum);
		double sum0=sum;
        sum/=100.0;
        if(sum0==0)
        {
        printf("Region %d\n",kase++);
        printf("Water level is %.2lf meters.\n",ans[n*m]);
        printf("0.00 percent of the region is under water.\n\n");
        }
        else{
		for(i = 1; i < n*m; i++){
			cnt = i*(ans[i+1]-ans[i]);
			if(sum>=cnt)
                sum -= cnt;
			else {flag= 0; break;}
		}
        printf("Region %d\n",kase++);
        printf("Water level is %.2lf meters.\n",flag? (ans[n*m]+sum/n/m): (ans[i]+sum/i));
        printf("%.2lf percent of the region is under water.\n\n",flag? (100): (i*1.0/n/m)*100);
	}
	}
	return 0;
}
