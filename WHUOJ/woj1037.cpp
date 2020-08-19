//加油站问题，在哪里做过
/*
相当于
for(int i=0;i<n;++i)
        {
            sum=sum+c[i]-d[i];
        }
        if(sum>=0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

如果进一步要给出哪个站:
首先如果从某个i出发，到j的时候sum(i, j)小于0了。
那么[i ,j]间所有的点k出发到j处的sum(k, j)都会小于0，
因为i能到k，自然sum(i, k)大于等于0，而sum(i, j) = sum(i, k-1)+sum(k, j)，
必然sum(k, j)要更小一点。那么[i, j]间的点都可以排除了。
于是可以直接从0点出发绕一圈，遇到i不行，就继续从i+1出发，
直到能跑完或者跑到n的位置处。
*/


#include<cstdio>
using namespace std;

int c[50001],d[50001];
int n,i,sumc,sumd;

int main(){

	while(scanf("%d",&n)&&n){
		sumc=0;sumd=0;
		for(i=1;i<=n;i++){
			scanf("%d",&c[i]);
			sumc=sumc+c[i];
		}
		for(i=1;i<=n;i++){
			scanf("%d",&d[i]);
			sumd=sumd+d[i];
		}
		if(sumc>=sumd)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}