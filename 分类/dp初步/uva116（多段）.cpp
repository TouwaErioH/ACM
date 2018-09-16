#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
const int INF = 1000000000;
int m, n, a[maxn][maxn], d[maxn][maxn], nextp[maxn][maxn];

int main() {
  while(scanf("%d%d", &m, &n) == 2 && m) {
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        scanf("%d", &a[i][j]);

    int ans = INF, first = 0;
    for(int j = n-1; j >= 0; j--) {    //逆推
      for(int i = 0; i < m; i++) {
        if(j == n-1) d[i][j] = a[i][j];   //边界
        else {
          int rows[3] = {i, i-1, i+1};
          if(i == 0) rows[1] = m-1;
          if(i == m-1) rows[2] = 0;
          sort(rows, rows+3);           //排序找到字典序最小的
          d[i][j] = INF;
          for(int k = 0; k < 3; k++) {
            int v = d[rows[k]][j+1] + a[i][j];
            if(v < d[i][j]) { d[i][j] = v; nextp[i][j] = rows[k]; }
          }
        }                                                             //以上得到第一列所有行出发的最小值
        if(j == 0 && d[i][j] < ans) { ans = d[i][j]; first = i; }
      }
    }
    printf("%d", first+1);    //输出第一列
    for(int i = nextp[first][0], j = 1; j < n; i = nextp[i][j], j++) printf(" %d", i+1);
    printf("\n%d\n", ans);    //输出其他列
  }
  return 0;
}
