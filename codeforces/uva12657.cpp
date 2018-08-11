#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100005;
int n, tleft[maxn], tright[maxn];

void link(int L, int R) {
  tright[L] = R; tleft[R] = L;
}

int main() {
  int m, kase = 0;
  while(scanf("%d%d", &n, &m) == 2) {
    for(int i = 1; i <= n; i++) {
      tleft[i] = i-1;
      tright[i] = (i+1) % (n+1);
    }
    tright[0] = 1; tleft[0] = n;
    int op, X, Y, inv = 0;

    while(m--) {
      scanf("%d", &op);
      if(op == 4) inv = !inv;
      else {
        scanf("%d%d", &X, &Y);
        if(op == 3 && tright[Y] == X) swap(X, Y);
        if(op != 3 && inv) op = 3 - op;
        if(op == 1 && X == tleft[Y]) continue;
        if(op == 2 && X == tright[Y]) continue;

        int LX = tleft[X], RX = tright[X], LY = tleft[Y], RY = tright[Y];
        if(op == 1) {
          link(LX, RX); link(LY, X); link(X, Y);
        }
        else if(op == 2) {
          link(LX, RX); link(Y, X); link(X, RY);
        }
        else if(op == 3) {
          if(tright[X] == Y) { link(LX, Y); link(Y, X); link(X, RY); }
          else { link(LX, Y); link(Y, RX); link(LY, X); link(X, RY); }
        }
      }
    }

    int b = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      b = tright[b];
      if(i % 2 == 1) ans += b;
    }
    if(inv && n % 2 == 0) ans = (long long)n*(n+1)/2 - ans;
    printf("Case %d: %lld\n", ++kase, ans);
  }
  return 0;
}
