#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,k;
int dp[1005][35],v[105],w[105],A[35],B[35];

void kPack()
{
    memset(dp,0,sizeof(dp));
    int i,j,t,a,b,c;
    for(i=1;i<=n;i++){
        for(j=m;j>=w[i];j--){
            for(t=1;t<=k;t++){
                A[t]=dp[j-w[i]][t]+v[i];//AB模拟取第i件物品和不取的过程
                B[t]=dp[j][t];
            }
            A[t]=B[t]=-1;a=b=c=1;//对AB进行新的排序,每次只取前k个
            while(c<=k&&(A[a]!=-1||B[b]!=-1)){
                if(A[a]>B[b])dp[j][c]=A[a],++a;//排序
                else dp[j][c]=B[b],++b;
                if(dp[j][c]!=dp[j][c-1])++c;//去重
            }
        }
    }
    printf("%d\n",dp[m][k]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)scanf("%d",&v[i]);
        for(int i=1;i<=n;i++)scanf("%d",&w[i]);
        kPack();
    }
    return 0;
}
