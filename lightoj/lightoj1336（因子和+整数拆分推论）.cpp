/*
对公式中任一项进行化简
1.当x有素因子2的时候，2所对应的括号内的和肯定是一个奇数，因为偶数加1一定是奇数。
2.除了2以外，所有的素数都是奇数，要使x得其他素因子对应的括号内的和为奇数，就必须保证x有偶数个该素因子，即ai必须为偶数。
3.满足上面两个条件的数，就是一个平方数，也就是说约数和为奇数的数x，它必定是一个平方数，当然这个数x乘上2也是满足2*x的约数和为奇数的。
所以只要减去用n减去sqrt(n)和sqrt(n/2)就是答案了。也可以找n以内的平方数的个数，以及2*平方数不超过n的数的所有个数和，用n减完之后就是答案。
;因为满足2的更高次幂也一定是2的倍数，不会重复计算
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
