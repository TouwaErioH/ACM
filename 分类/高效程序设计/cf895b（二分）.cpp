#include <bits/stdc++.h>
const int MAX=1e5+10;
typedef long long LL;
using namespace std;
LL a[100005];
int main (){
    LL n,x,k;
    while (scanf ("%lld%lld%lld",&n,&x,&k)!=EOF){
        for (int i=0;i<n;i++) scanf ("%lld",&a[i]);
        sort(a,a+n);
        LL sum=0;
        for (int i=0;i<n;i++){
            LL tt=a[i]%x==0?a[i]:(a[i]/x+1)*x;
            sum+=lower_bound(a,a+n,tt+k*x)-lower_bound(a,a+n,max(tt+(k-1)*x,a[i]));
        }
        printf ("%lld\n",sum);
    }
    return 0;
}

---------------------

本文来自 MM__1997 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/mm__1997/article/details/78668899?utm_source=copy 

/*
把n个数从小到大排序，然后求出大于等于a[i]的第一个x的倍数p
然后只需二分查找计算出p+k*x 和 max（a[i],p+(k-1)*x）之间数的个数求和即可。

 */
;//p+kx得到k+1个，p+k-1*x得k个，之间的符合