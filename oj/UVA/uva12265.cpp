#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1010;

char s[maxn][maxn];
int height[maxn], ans[maxn*2];

struct Rect {
  int c, h;
  Rect(int c=0, int h=0):c(c),h(h){}
};

Rect rect[maxn]; // stack

int main() {
  int n, m, T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%s", s[i]);

    memset(height, 0, sizeof(height));
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i ++) {
      int top = -1;
      for(int j = 0; j < m; j ++) {
        if(s[i][j] == '#') {
          height[j] = 0;
          top = -1; // clear stack
        } else {
          height[j]++;
          Rect r(j, height[j]);
          if(top < 0) rect[++top] = r; //前面的高度为0了
          else {
            while(top >= 0 && r.h <= rect[top].h) r.c = rect[top--].c;  //因为-c+h，c大，h还小，那么肯定不是最优左上角
            if(top < 0 || r.h - r.c > rect[top].h - rect[top].c) rect[++top] = r;//新的一列高度最小，就删掉了其他的，只留这个高度
          }
          ans[j-rect[top].c+rect[top].h+1]++;
        }
      }
    }
    for(int i = 1; i <= n + m; i++)
      if(ans[i]) printf("%d x %d\n", ans[i], i*2);
  }
  return 0;
}
