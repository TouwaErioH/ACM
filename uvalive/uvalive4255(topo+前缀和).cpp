#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 30;

char str[MAXN * 10];
int in[MAXN], vis[MAXN], g[MAXN][MAXN], sum[MAXN];
int n;

void toposort() {
    int d = 0, low = -10;
    while (d <= n) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= n; i++) {
            if (in[i] == 0) {
                sum[i] = low;
                in[i] = -1;
                vis[i] = 1;
                d++;
            }
        }
        low++;
        for (int i = 0; i <= n; i++) {
            if (vis[i]) {
                for (int j = 0; j <= n; j++)
                    if (g[i][j])
                        in[j]--;
            }
        }
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        scanf("%s", str);
        memset(in, 0, sizeof(in));
        memset(g, 0, sizeof(g));
        memset(sum, 0, sizeof(sum));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (str[cnt] == '+') {
                    in[j]++;
                    g[i - 1][j] = 1;
                }
                else if (str[cnt] == '-') {
                    in[i - 1]++;
                    g[j][i - 1] = 1;
                }
                cnt++;
            }
        }
        toposort();
        for (int i = 1; i <= n; i++) {
            //if (i == 1)
                //printf("%d", sum[i] - sum[i - 1]);
            //else
                printf("%d ", sum[i] - sum[i - 1]);
        }
        printf("\n");
    }
    return 0;
}
/*
使用连续和转化为前缀和之差的技巧，将前缀和当做一个顶点，将前缀和当成点
将大小关系作为边  求出满足题意的前缀和的拓扑序
那么只需要让拓扑序大的比小的大1
之后用拓扑排序求解，先着一个入度为0的顶点，删除其相关的边，循环操作。
s[i][j]转化为sum[j] - sum[i-1]
*/
