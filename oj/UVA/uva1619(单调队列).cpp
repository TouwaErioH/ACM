#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
typedef long long LL;
using namespace std;
const int maxn=100010;
int n;
int a[maxn],L[maxn],R[maxn];//l[i]表示以a[i]为最小值的左半区间的最左边端点，r[i]表示以a[i]为最小值的右半区间的最右边端点
LL sum[maxn];

int main(){
    int t=0;
    while(scanf("%d",&n)==1){
        if(t)
            printf("\n");
        t++;
        sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
      deque<int>q;
      for(int i=1;i<=n;i++){
        while(!q.empty()&&a[i]<=a[q.back()]){
            R[q.back()]=i-1;
            q.pop_back();
        }
        if(q.empty())L[i]=1;
        else L[i]=q.back()+1;
        q.push_back(i);
      }
      while(!q.empty()){
        R[q.back()]=n;
        q.pop_back();
      }
      LL ans=0;
      int ansL=1,ansR=1;
      for(int i=1;i<=n;i++){
        if(ans<(sum[R[i]]-sum[L[i]-1])*a[i]){
            ans=(sum[R[i]]-sum[L[i]-1])*a[i];
            ansL=L[i],ansR=R[i];
        }
      }
      printf("%lld\n",ans);
      printf("%d %d\n",ansL,ansR);
    }
return 0;
}
