#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10005;

int main() {
    int N, Q, qu,a[maxn], kase = 0;
    while(scanf("%d%d", &N, &Q) == 2 && N) {
        printf("CASE# %d:\n", ++kase);
        for(int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + N);
        while(Q--) {
            scanf("%d", &qu);
            int p = lower_bound(a, a + N, qu) - a;
            if(a[p] == qu)
            {
            printf("%d found at %d\n", qu, p + 1);
            }
            else
            {
            printf("%d not found\n", qu);
            }
        }
    }
    return 0;
}
