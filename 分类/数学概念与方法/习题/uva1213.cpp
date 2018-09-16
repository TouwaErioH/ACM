#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
const int maxn = 1124;
bool isprime[maxn];
int prime[maxn];
int pcnt;
int n, k;
LL dp[maxn][20];


void eulerPrime() {
  prime[0] = prime[1] = 0;
  for(int i = 2; i <= maxn; i++) {
    if(isprime[i]) prime[++pcnt] = i;
    for(int j = 1; j <= pcnt; j++) {
          if(i * prime[j] > maxn) break;
        isprime[i*prime[j]] = 0;
        if(i % prime[j] == 0) break;
    }
  }
}

int main() {
    memset(isprime, true, sizeof(isprime));
    pcnt = 0;
    eulerPrime();
    dp[0][0] = 1;
    for(int k = 1; k < pcnt+1; k++) {
        for(int i = 1122; i >= prime[k]; i--) {
            for(int j = 1; j <=14; j++) {
                dp[i][j] += dp[i-prime[k]][j-1];
            }
        }
    }
    while(scanf("%d%d",&n,&k)&& n+k) {
        printf("%lld\n", dp[n][k]);
    }
    return 0;
}
