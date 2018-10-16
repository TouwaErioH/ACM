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
    nx = unique(x, x+nx) - x;           ////�����п����õ����޸Ľ������ŵ�x������

    int t = 0;
    for(int i = 0; i < nx; i++) {
      dp[0][i] = INF;
      if(x[i] == h[0]) dp[0][i] = 0;
    }
    for(int i = 1; i < n; i++) {
      int k = 0;                          ////��Ϊֻ���棬ż���ֱ仯����iֻ������i-1ʱ����������˿����ù��������Ż�
      for(int j = 0; j < nx; j++) {   //��С����ö��xֵ����Ϊ������Ҫ�õ���xֵ����x�����У���˵ȼ���ö���±�
                                       //dp[t][j]�����״̬(Ҳ���Ǹ���i�������ĳ���x[j]�ı�ʾ)
        while(k < nx && x[k] < x[j]-d) //�õ�y�� ǰһ���ĸ߶�
            k++;
        while(k+1 < nx && x[k+1] <= x[j]+d && dp[t][k+1] <= dp[t][k]) //������ʵ�ǵ�������
            k++; // min in sliding window
        if(dp[t][k] == INF)
            dp[t^1][j] = INF;//֮ǰ��y��û�У��϶��ﲻ��Ŀǰ��x
        else
            dp[t^1][j] = dp[t][k] + abs(x[j] - h[i]);  //�õ�x[j]����Ӧ����Сֵ   j������abs���ȼ�������(t,k)Ҳ�ȼ�����
      }
      t ^= 1;
    }
    for(int i = 0; i < nx; i++)
      if(x[i] == h[n-1])
        cout << dp[t][i] << "\n";
  }
  return 0;
}
