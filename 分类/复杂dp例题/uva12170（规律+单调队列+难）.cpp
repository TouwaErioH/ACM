#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn = 100 + 5;
const int maxx = maxn*maxn*2;
const LL  INF = (1LL << 60);

LL h[maxn], x[maxx], dp[2][maxx];

int main () {
  int T;
  cin >> T;
  while(T--) {
    int n;
    LL d;
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> h[i];
    if(abs(h[0] - h[n-1]) > (n-1)*d) {
      cout << "impossible\n";
      continue;
    }

    int nx = 0;

    for(int i = 0; i < n; i++)
      for(int j = -n+1; j <= n-1; j++)
        x[nx++] = h[i] + j*d;
    sort(x, x+nx);
    nx = unique(x, x+nx) - x;           ////把所有可能用到的修改结果都存放到x数组中

    int t = 0;
    for(int i = 0; i < nx; i++) {
      dp[0][i] = INF;
      if(x[i] == h[0]) dp[0][i] = 0;
    }
    for(int i = 1; i < n; i++) {
      int k = 0;                          ////因为只有奇，偶两种变化，且i只依赖于i-1时候的情况，因此可以用滚动数组优化
      for(int j = 0; j < nx; j++) {   //从小到大枚举x值，因为所有需要用到的x值都在x数组中，因此等价于枚举下标
                                       //dp[t][j]是这个状态(也就是改了i个数，改成了x[j]的表示)
        while(k < nx && x[k] < x[j]-d) //得到y， 前一个的高度
            k++;
        while(k+1 < nx && x[k+1] <= x[j]+d && dp[t][k+1] <= dp[t][k]) //这里其实是单调队列
            k++; // min in sliding window
        if(dp[t][k] == INF)
            dp[t^1][j] = INF;//之前的y都没有，肯定达不到目前的x
        else
            dp[t^1][j] = dp[t][k] + abs(x[j] - h[i]);  //得到x[j]处对应的最小值   j递增，abs就先减后增，(t,k)也先减后增
      }
      t ^= 1;
    }
    for(int i = 0; i < nx; i++)
      if(x[i] == h[n-1])
        cout << dp[t][i] << "\n";
  }
  return 0;
}
