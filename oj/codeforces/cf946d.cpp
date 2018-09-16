#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=505;
const int INF=0x3f3f3f3f;

char s[N][N];
int num[N],pos[N][N],dp[N],v[N][N];  //pos[i][j]对应第i个字符串第j个'1'的位置，num[i]记录第i个字符串'1'的数量
                                     //v[i][k]即第i段字符串删除k个1，空闲的时间
int main(){
    int n,m,lim;
    scanf("%d%d%d",&n,&m,&lim);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++){
            if(s[i][j]=='1'){
                num[i]++;
                pos[i][num[i]]=j;
            }
        }
    }
    //处理出v[i][k],
    for(int i=0;i<n;i++){
        //枚举k
        for(int k=0;k<=min(num[i]-1,lim);k++){
            int res=INF;
            for(int p=0;p<=k;p++){
            res=min(res,pos[i][num[i]-k+p]-pos[i][p+1]+1);//右移位-左移位
            }
            v[i][k]=m-res;
        }
        v[i][num[i]]=m;
    }
    //分组背包
    memset(dp,0,sizeof(dp));//dp为不上学的时间
    for(int i=0;i<n;i++){
        for(int j=lim;j>=0;j--){
            for(int k=0;k<=min(j,m);k++){
                dp[j]=max(dp[j],dp[j-k]+v[i][k]);
            }
        }
    }
    printf("%d\n",m*n-dp[lim]);
    return 0;
}
