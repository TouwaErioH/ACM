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
��Բ�Ӵ�С�������ĳ��Բu�����˻�δ�����ǵ�Բv���ͽ�u,v��һ���ߣ�һ���Ǵ��Բ����С��Բ����
�����������һ��ɭ�֣�����ÿһ���������ڵ�����һ�������ӽڵ������Ȼ����һ��̰�ģ�
һ��Ҫ����ѡ������Բ����˿��԰Ѹ��ڵ�ֳɵ�һ�����ϣ��Ѹ��ڵ���ӽڵ�ֳɵڶ������ϣ�
Ȼ�������ȵ���ż��ѡ��ڵ㼴��

֤����һ��Բ�����ΪSi�������ѡ�����Բ�������Բ�Ĺ���Ϊ-Si��
����Բ�������׵����-�����׵����<=Si����������ѡ���Բ����������ڵĹ��ױ�Ϊ����
*/
