#include<iostream>
#include<cstdio>
using namespace std;
int T, k, a, b;
long long c(int i) {
  return i == 0 ? 1 : c(i-1)*3;
}

long long f(int k, int i) {
  if(i == 0) return 0;
  if(k == 0) return 1;

  int k2 = 1 << (k-1);
  if(i >= k2) return f(k-1, i-k2) + c(k-1)*2;
  else return f(k-1, i) * 2;
}

int main() {
  cin >> T;
  for(int kase = 1; kase <= T; kase++){
    cin >> k >> a >> b;
    printf("Case %lld: %lld\n",kase,f(k,b)-f(k,a-1));
  }
  return 0;
}
