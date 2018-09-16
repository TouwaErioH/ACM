#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;

LL doit(LL x, LL n, LL mod) {
    LL res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return x != 1;
}

int main(void)
{
    int n;
    while (scanf("%d", &n)&&n) {
        bool ans = true;
        if (isprime(n))
        {
        printf("%d is normal.\n", n);
        continue;
        }
        for (int i = 2; i < n; i++) {
            if (doit(i, n, n) != i) {
                ans = false;
                break;
            }
        }
        if (ans) printf("The number %d is a Carmichael number.\n", n);
        else printf("%d is normal.\n", n);
    }
    return 0;
}
