#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int a[200005];
int main(){
    map<long long,int> amap,bmap;   //��������ԭ���Ƿ�ֹ1,1,1,��27�����ƽ��
    int n;
    long long k;                   //Ϊʲô��ll
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
