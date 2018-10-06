#include<cstdio>
using namespace std;

const int maxn = 100000 + 5;

int n, L;
char s[maxn];
int sum[maxn], p[maxn]; // average of i~j is (sum[j]-sum[i-1])/(j-i+1)

// compare average of x1~x2 and x3~x4    //x1-x2��б�ʴ���x3-x4����1
int compare_average(int x1, int x2, int x3, int x4) {
  return (sum[x2]-sum[x1-1]) * (x4-x3+1) - (sum[x4]-sum[x3-1]) * (x2-x1+1);
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d%s", &n, &L, s+1);

    sum[0] = 0;
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + s[i] - '0';

    int ansL = 1, ansR = L;

    // p[i..j) is the sequence of candidate start points
    int i = 0, j = 0;   //j����ʼ�������ұߵĵ㣬p[j]�����Ǹ����������е�λ��
    for (int t = L; t <= n; t++) { // end point ��ö�ٵ��Ҷ˵�
      while (j-i > 1 && compare_average(p[j-2], t-L, p[j-1], t-L) >= 0) j--; // remove concave points
      //t-l���¼ӵĵ�(��һ��t-l+1����forѭ��t++��)��j-1(��һ��j++��)��ԭ�����ұߵĵ㣬�����ұ߿�ʼ�ж��Ƿ���͹

      p[j++] = t-L+1; // new candidate   //ע����һ��ѭ���Ѿ�ȥ�����������͹��(j--)��

      while (j-i > 1 && compare_average(p[i], t, p[i+1], t) <= 0) i++; // update tangent point�е�

      int c = compare_average(p[i], t, ansL, ansR);  //����
      if (c > 0 || c == 0 && t - p[i] < ansR - ansL) {
        ansL = p[i]; ansR = t;
      }
    }
    printf("%d %d\n", ansL, ansR);
  }
  return 0;
}
