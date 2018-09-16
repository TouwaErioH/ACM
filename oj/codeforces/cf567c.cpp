#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int a[200005];
int main(){
    map<long long,int> amap,bmap;   //用两个的原因是防止1,1,1,得27等类似结果
    int n;
    long long k;                   //为什么用ll
    scanf("%d%lld",&n,&k);
    for(int i=0; i<n; ++i){
        scanf("%d",a+i);
        ++bmap[a[i]];
    }
    long long ans=0;
    for(int i=0; i<n; ++i){
        --bmap[a[i]];
        if(a[i]%k==0){
            ans+=(long long)amap[a[i]/k]*bmap[a[i]*k];
        }
        ++amap[a[i]];
    }
    printf("%lld",ans);
    return 0;
}
