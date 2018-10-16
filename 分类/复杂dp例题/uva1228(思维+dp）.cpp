#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 65;

int n, d, K[maxn];
long long f[maxn][maxn];
unsigned long long minv, maxv;  //ull ！！！
int zcnt = 0, ocnt = 0;
int Z[maxn], O[maxn];

bool can_receive_zero(int i, int j) {
  return i+1 <= zcnt && (j == ocnt || O[j]+d >= Z[i]);
}

bool can_receive_one(int i, int j) {
  return j+1 <= ocnt && (i == zcnt || Z[i]+d >= O[j]);
}

void solve() {
  // compute Z and O
  ocnt = zcnt = 0;
  for(int i = 0; i < n; i++)
    if(K[i] == 1) O[ocnt++] = i;
    else Z[zcnt++] = i;

  minv = maxv = 0;
  int i = 0, j = 0;
  while(i < zcnt || j < ocnt) {
    if(can_receive_zero(i, j))      //贪心策略0越前越好
        { i++; minv = minv * 2; }
    else
        { j++; minv = minv * 2 + 1; }
  }
  i = j = 0;
  while(i < zcnt || j < ocnt) {
    if(can_receive_one(i, j)) { j++; maxv = maxv * 2 + 1; }
    else { i++; maxv = maxv * 2; }
  }


  // dp
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for(int i = 0; i <= zcnt; i++)
    for(int j = 0; j <= ocnt; j++) {
      if(can_receive_zero(i, j))
        f[i+1][j] += f[i][j];
      if(can_receive_one(i, j))
        f[i][j+1] += f[i][j];
    }
  cout << f[zcnt][ocnt] << " " << minv << " " << maxv << "\n";
}

int main() {
  int kase = 0;
  unsigned long long k;
  while(cin >> n >> d >> k) {
    for(int i = 0; i < n; i++) {
      K[n-i-1] = k % 2; k /= 2;
    }
    cout << "Case " << ++kase << ": ";
    solve();
  }
  return 0;
}
