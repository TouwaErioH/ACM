#include <cstdio>
using namespace std;
const int maxn = 1000005;
bool nhp[maxn];
int hp[maxn],num;
int cnt[maxn];
void init() {
    for(int i = 5; i < 1005; i += 4)
        if(!nhp[i])
            for(int j = i * i; j < maxn; j += i)
                nhp[j] = true;
    for(int i = 5; i < maxn; i+=4)
        if(!nhp[i]) hp[num++] = i;
    for(int i = 0; i < num; ++i)
        for(int j = 0; j < num && hp[i] * hp[j] < maxn; ++j)
            cnt[hp[i]*hp[j]] = 1;
    for(int i = 1; i < maxn; ++i) cnt[i] += cnt[i - 1];
}
int main() {
    init();
    int n;
    while(scanf("%d", &n) && n)
        printf("%d %d\n", n, cnt[n]);
    return 0;
}