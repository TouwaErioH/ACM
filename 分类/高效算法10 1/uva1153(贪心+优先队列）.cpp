#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 800005;
const int N = 2000005;

struct order{
    int q, d;
    bool operator < (const order &a) const {
        return q<a.q;
}
}o[MAXN];

int cmp (order a, order b) {
    return a.d < b.d;
}

int n;
int solve() {
    priority_queue<int> done;
    int sum = 0, temp;
    for (int i = 0; i < n; i++) {
        if (o[i].q + sum <= o[i].d) {
            done.push(o[i].q);
            sum += o[i].q;
        }
        else if (!done.empty()){
            temp = done.top();
            if (temp > o[i].q) {
                sum = sum - temp + o[i].q;
                done.pop();
                done.push(o[i].q);
            }
        }
    }
    return done.size();
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &o[i].q, &o[i].d);
        sort(o, o + n, cmp);
        printf("%d\n", solve());
        if(T)
            printf("\n");
    }
    return 0;
}
