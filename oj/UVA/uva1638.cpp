#include<iostream>
using namespace std;

const int maxn = 20;
long long f[maxn+1][maxn+1][maxn+1];

void init()
{
      f[1][1][1] = 1;
  for(int i = 2; i <= maxn; i++)
    for(int j = 1; j <= i; j++)
      for(int k = 1; k <= i; k++) {
        f[i][j][k] = f[i-1][j][k] * (i-2);
        if(j > 1) f[i][j][k] += f[i-1][j-1][k];
        if(k > 1) f[i][j][k] += f[i-1][j][k-1];
      }
}
int main() {
init();
  int T, n, L, R;
  cin >> T;
  while(T--) {
    cin >> n >> L >> R;
    cout << f[n][L][R] <<endl;
  }
  return 0;
}
