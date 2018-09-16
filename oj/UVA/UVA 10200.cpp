
// 打表，费马小定理+快速幂，欧拉，朴素

#include <cstdio>
#include <cmath>
using namespace std;

const int MAX_N = 10010;

int sum[MAX_N];

bool isprime(int x)
{
    if(x == 1) return false;
    int m = (int)sqrt(x + 0.5);
    for(int i = 2; i <= m; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void init()
{
    sum[0] = 1;
    for(int i = 1; i <= 10000; i++){
        sum[i] = sum[i - 1];
        if(isprime(i * i + i + 41)) sum[i]++;
    }
}

int main()
{
    init();
    int a, b;
    while(~scanf("%d%d", &a, &b)){
        int cnt ;
        if(a == 0) cnt = sum[b];
        else cnt = sum[b] - sum[a - 1];
        double ans = 1.0 * cnt / (b - a + 1);//float 也可
        printf("%.2lf\n", ans * 100 + 1e-5);//1e-8ok，或者避开浮点运算
    }
    return 0;
}
