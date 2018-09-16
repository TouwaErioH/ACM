#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int T, n, k;
  while(cin >> T){
        int kase=0;
  for(int i=1; i <= T; i++) {
    cin >> n >> k;
    LL b = 1LL << k;
    LL a = b - k - 1;
    LL g=gcd(a,b);
    a/=g;
    b/=g;
    printf("Case #%d: %lld/%lld\n",++kase,a,b);
  }
}
  return 0;
}
