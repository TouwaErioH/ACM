#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MX = 1005;
const double PI = acos(-1.0);
struct point {
    double x, y, r, v;
} p[MX];

struct Edge {
    int v, nxt;
} E[MX];

int n, tot, pre[MX], head[MX];
double dp[MX], f[MX], ans;
bool cmp(const point& p1, const point& p2) {
    return p1.r < p2.r;
}

double dis(int i, int j) {
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}

void add(int u, int v) {
    E[tot].v = v;
    E[tot].nxt = head[u];
    head[u] = tot++;
}


void dfs(int u, int dep) {
    for (int i = head[u]; i!=-1; i = E[i].nxt)
    {
        int v = E[i].v;
        if (dep % 2 == 0) ans += p[v].v;
        else ans -= p[v].v;
        dfs(v, dep ^ 1);
    }
}

int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].r);
        p[i].v = p[i].r * p[i].r * PI;
    }
    sort(p + 1, p + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (!pre[j] && dis(i, j) < p[i].r + p[j].r)
                pre[j] = i, add(i, j);
        }
    }

    for (int i = 1; i <= n; i++)
        if (!pre[i])
            {
            ans += p[i].v;
            dfs(i, 0);
            }
    printf("%.8f\n", ans);
    return 0;
}

/*
将圆从大到小排序，如果某个圆u覆盖了还未被覆盖的圆v，就将u,v连一条边（一定是大的圆覆盖小的圆），
这样可以组成一个森林，对于每一颗树，父节点的面积一定大于子节点面积，然后有一个贪心：
一定要尽量选面积大的圆，因此可以把根节点分成第一个集合，把根节点的子节点分成第二个集合，
然后根据深度的奇偶性选择节点即可

证明：一个圆的面积为Si，如果不选择这个圆，则这个圆的贡献为-Si，
其子圆中正贡献的面积-负贡献的面积<=Si，因此如果不选这个圆则这颗子树内的贡献必为负。
*/
