#include<iostream>
using namespace std;

int main() {
  int S[20], kase = 0, n;
  while(scanf("%d",&n)==1 && n) {
    for(int i = 0; i < n; i++) scanf("%d",&S[i]);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      long long temp = 1;
      for(int j = i; j < n; j++) {
        temp *= S[j];
        if(temp > ans) ans = temp;
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n",++kase,ans);
  }
  return 0;
}
