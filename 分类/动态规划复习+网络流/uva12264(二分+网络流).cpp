#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 250, INF = 0x3f3f3f3f;
int a[maxn], border[maxn];
string map[maxn];
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) :from(u), to(v), cap(c), flow(f) {}
};
struct EdmondsKarp
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int p[maxn];

    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            G[i].clear();
        }
        edges.clear();
        memset(p, 0, sizeof(p));//²»ÐèÒª£¿
    }
    void AddEdge(int u, int v, int c)
    {
        edges.push_back(Edge(u, v, c, 0));
        edges.push_back(Edge(v, u, 0, 0));
        m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }
    int MaxFlow(int s, int t)
    {
        int flow = 0;
        for (;;)
        {
            memset(a, 0, sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (int i = 0; i < G[u].size(); i++)
                {
                    Edge& e = edges[G[u][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        a[e.to] = min(a[u], e.cap - e.flow);
                        Q.push(e.to);
                        p[e.to] = G[u][i];
                    }
                }
                if (a[t])
                    break;
            }
            if (!a[t])
                break;
            for (int i = t; i != s; i = edges[p[i]].from)
            {
                edges[p[i]].flow += a[t];
                edges[p[i] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
}E;

int Build(int val,int N)
{
    for (int i = 1; i <= N; i++)
    {
        if (!a[i])
            continue;
        E.AddEdge(0, i, a[i]);
        E.AddEdge(i, i + N, a[i]);
        for (int j = 1; j <= N; j++)
            if (map[i][j] == 'Y')
            {
                if (!a[j])
                    border[i] = true;         //border
                else
                    E.AddEdge(i, j + N, INF);
            }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (border[i])
        {
            E.AddEdge(i + N, 2 * N + 1, val);
            ans += val;
        }
        else if (a[i])
        {
            E.AddEdge(i + N, 2 * N + 1, 1);
            ans++;
        };
        return ans;
}
void solve(int n)
{
    int a, b, ans;
    int l = 0, r = 10010;
    while (l<r)
    {
        E.init(2 * n + 2);
        int mid = l+(r-l)/2;
        a = Build(mid, n);
        b = E.MaxFlow(0, 2 * n + 1);
        if (a == b)
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid;
    }
    cout << ans << endl;
}

void input(int n){
        memset(a, 0, sizeof(a));
        memset(border, 0, sizeof(border));
        for (int i = 0; i < maxn; i++)
            map[i].clear();

        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            cin >> map[i];
            map[i] = '0'+map[i];
        }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        input(n);
        solve(n);
    }
    return 0;
}
