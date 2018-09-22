#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n;
int x,k,a[100005];

int main(){
    scanf("%d%d%d",&n,&x,&k);
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    sort(a,a+n);
    LL sum = 0;
    for(int i = 0; i < n; i ++){
        LL p = ceil(a[i]*1.0/x)*x;
        sum += lower_bound(a,a+n,p+k*x) - lower_bound(a,a+n,max(a[i],p+(k-1)*x));//p+kx得到k+1个，p+k-1*x得k个，之间的符合
    }
    printf("%I64d\n",sum);
    return 0;
}

/*
把n个数从小到大排序，然后求出大于等于a[i]的第一个x的倍数p
然后只需二分查找计算出p+k*x 和 max（a[i],p+(k-1)*x）之间数的个数求和即可。

 */
