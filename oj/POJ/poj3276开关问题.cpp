#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
const int N=5000+10;
int f[N],dir[N],n;
int solve(int k){
   int cnt=0,sum=0;
   memset(f,0,sizeof(f));
   for(int i=1;i<=n-k+1;i++){
    if((dir[i]+sum)%2){
         cnt++;
         f[i]=1;
    }
    sum+=f[i];
    if(i-k+1>=1) sum-=f[i-k+1];
   }
   for(int i=n-k+2;i<=n;i++){
      if((dir[i]+sum)%2)
   return -1;
      if(i-k+1>=1) sum-=f[i-k+1];
   }
   return cnt;
}

int main(){
   while(scanf("%d",&n)==1){
       for(int i=1;i<=n;i++){
          char c;scanf(" %c",&c);
          if(c=='B') dir[i]=1;
       }
       int K=1,M=n;
       for(int i=1;i<=n;i++){
        int  m=solve(i);
if(m>=0&&M>m)
         {
              M=m;K=i;
          }
       }
       printf("%d %d\n",K,M);
   }
return 0;
}
