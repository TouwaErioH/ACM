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

�������� MM__1997 ��CSDN ���� ��ȫ�ĵ�ַ������https://blog.csdn.net/mm__1997/article/details/78668899?utm_source=copy 

/*
��n������С��������Ȼ��������ڵ���a[i]�ĵ�һ��x�ı���p
Ȼ��ֻ����ֲ��Ҽ����p+k*x �� max��a[i],p+(k-1)*x��֮�����ĸ�����ͼ��ɡ�

 */
;//p+kx�õ�k+1����p+k-1*x��k����֮��ķ���