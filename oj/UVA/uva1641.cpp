#include<cstdio>
#include<iostream>
using namespace std;

char mp[999];
int main() {
  int h, w;

  while(scanf("%d%d", &h, &w) == 2) {
    int ans = 0, cnt = 0;
    while(h--) {
      scanf("%s", mp);
      int flag = 0;
      for(int i = 0; i < w; i++) {
        if(mp[i] == '/' || mp[i] == '\\') {
                cnt++;
                flag = !flag;
        }
        else if(flag) ans++;
      }
    }
    printf("%d\n", ans + cnt/2);
  }
  return 0;
}
