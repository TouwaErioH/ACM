#include<cstdio>
#include<iostream>
using namespace std;
int main() {
  int n, D, p, L, v, kase = 0;
  while((cin>>n>>D)&& D) {
    double ans = 0;
    while(n--) {
      cin>>p>>L>>v;
      D -= L; ans += 2.0 * L / v;
    }
    printf("Case %d: %.3lf\n\n", ++kase, ans + D);
  }
  return 0;
}
