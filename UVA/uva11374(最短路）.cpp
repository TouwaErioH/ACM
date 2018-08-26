/*
�ڲ�ʹ������Ʊ������¼����������·���ֱ�������s��ÿһ������·ds[N]��
�Լ��յ�t��ÿһ������·dt[N]������¼��㵽�յ�����·Min��
Ȼ��ö������Ʊ������Ʊ��ʼվ��u�� ��ֹվ��v�� ����cos����
ʹMin = min��ds[u] + dt[v] + cos, ds[v] + dt[u] + cos��,����¼��ʹ�õ�����Ʊ��u��v��
ά�������Min���������ŵ������ʹ������Ʊ�����·���ѣ�Ȼ�����pre���飬�Լ���¼��u��v���·������
�п���ֻ���������ﲻ���յ㣬��ʱ������ĳվ�쳵��
�������������һ���ܵ����յ�Ȼ�������ӡ·�����ܻ����,
��Ϊ��ʱû��һ������·����
��ʱ�ӻ�����վ���յ�Ӧ����һ���ӡ
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 505;
const int M = 5005;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int n, s, t;
int vis[N], d[2][N], en;
int head[M];
int pre[2][N];

struct node {
    int to, dis, next;
}edge[N * M];

void init();

void addEdge(int u,int v,int x) {
    edge[en].to = v;
    edge[en].next = head[u];
    edge[en].dis = x;
    head[u] = en++;

    edge[en].to = u;
    edge[en].next = head[v];
    edge[en].dis = x;
    head[v] = en++;
}

void SPFA(int flag) {
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        d[flag][i] = INF;
        vis[i] = 0;
        pre[flag][i] = -1;
    }
    d[flag][s] = 0;
    vis[s] = 1;
    pre[flag][s] = s;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front();
        vis[u] = 0;
        Q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(d[flag][u] + edge[i].dis < d[flag][v]) {
                d[flag][v] = d[flag][u] + edge[i].dis;
                pre[flag][v] = u;
                if(!vis[v]) {
                    Q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

void input() {
    int num, a, b, c;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %d %d", &a, &b, &c);
        addEdge(a, b, c);
    }
}

void print(int x) {
    if (pre[0][x] == x) {
        printf("%d", x);
        return;
    }
    print(pre[0][x]);
    printf(" %d", x);
}

void solve() {
    int num, a, b, c;
    int Min = d[0][s], tU = -1, tV = -1;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (d[0][a] + d[1][b] + c < Min) {
            Min = d[0][a] + d[1][b] + c;
            tU = a, tV = b;
        }
        if (d[0][b] + d[1][a] + c < Min) {
            Min = d[0][b] + d[1][a] + c;
            tU = b, tV = a;
        }
    }
    if (tU == -1) {
        print(s);
        puts("");
        printf("Ticket Not Used\n");
    } else {
        print(tU);
        for (int i = tV; i != s; i = pre[1][i]) printf(" %d", i);
        printf(" %d\n", s);
        printf("%d\n", tU);
    }
    printf("%d\n", Min);
}

int main() {
    int Case = 1;
    while (scanf("%d %d %d", &n, &s ,&t) == 3) {
        memset(head, -1, sizeof(head));
        if (Case != 1) puts("");
        Case++;
        input();
        SPFA(0);
        s = t;
        SPFA(1);
        solve();
    }
    return 0;
}
