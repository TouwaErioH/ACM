/*
�Թ�ʽ����һ����л���
1.��x��������2��ʱ��2����Ӧ�������ڵĺͿ϶���һ����������Ϊż����1һ����������
2.����2���⣬���е���������������Ҫʹx�����������Ӷ�Ӧ�������ڵĺ�Ϊ�������ͱ��뱣֤x��ż�����������ӣ���ai����Ϊż����
3.��������������������������һ��ƽ������Ҳ����˵Լ����Ϊ��������x�����ض���һ��ƽ��������Ȼ�����x����2Ҳ������2*x��Լ����Ϊ�����ġ�
����ֻҪ��ȥ��n��ȥsqrt(n)��sqrt(n/2)���Ǵ��ˡ�Ҳ������n���ڵ�ƽ�����ĸ������Լ�2*ƽ����������n���������и����ͣ���n����֮����Ǵ𰸡�
;��Ϊ����2�ĸ��ߴ���Ҳһ����2�ı����������ظ�����
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++)
    {
        ll n, sum;
        scanf("%lld", &n);
        sum = n;
        sum -= (int)sqrt(n);
        sum -= (int)sqrt(n/2);
        printf("Case %d: %lld\n", kase, sum);
    }
    return 0;
}
