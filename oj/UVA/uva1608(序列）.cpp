#include<cstdio>
#include<map>
using namespace std;

const int maxn = 200000 + 5;
int A[maxn], last[maxn], nextp[maxn];
map<int, int> cur;

bool duli(int p, int L, int R) {
  return last[p] < L && nextp[p] > R;
}

bool check(int L, int R) {
  if(L >= R) return true;
  for(int d = 0; L+d <= R-d; d++) {
    if(duli(L+d, L, R))                        //L+d位置上的元素 独立
      return check(L, L+d-1) && check(L+d+1, R);
    if(L+d == R-d) break;
    if(duli(R-d, L, R))
      return check(R-d+1, R) && check(L, R-d-1);
  }
  return false;
}

int main() {
  int T, n;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    cur.clear();
    for(int i = 0; i < n; i++) {
      scanf("%d", &A[i]);
      if(!cur.count(A[i]))
        last[i] = -1;
      else
        last[i] = cur[A[i]];
      cur[A[i]] = i;
    }
    cur.clear();
    for(int i = n-1; i >= 0; i--) {
      if(!cur.count(A[i]))
        nextp[i] = n;
      else
      nextp[i] = cur[A[i]];
      cur[A[i]] = i;
    }

    if(check(0, n-1))
        printf("non-boring\n");
    else
        printf("boring\n");
  }
  return 0;
}
