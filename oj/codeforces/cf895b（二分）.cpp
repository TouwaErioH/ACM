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
        sum += lower_bound(a,a+n,p+k*x) - lower_bound(a,a+n,max(a[i],p+(k-1)*x));//p+kx�õ�k+1����p+k-1*x��k����֮��ķ���
    }
    printf("%I64d\n",sum);
    return 0;
}

/*
��n������С��������Ȼ��������ڵ���a[i]�ĵ�һ��x�ı���p
Ȼ��ֻ����ֲ��Ҽ����p+k*x �� max��a[i],p+(k-1)*x��֮�����ĸ�����ͼ��ɡ�

 */
