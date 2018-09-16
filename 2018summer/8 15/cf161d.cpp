#include<bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int tot, head[maxn];
int dp[maxn][510], ans;

struct Edge
{
    int to, next;
} edge[maxn << 1];

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u, int fa, int k)
{
    dp[u][0] = 1;
    for (int i = 1; i <= k; i++)
        dp[u][i] = 0;

    for (int i = head[u]; i!=-1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa) continue;

        dfs(v, u, k);
        for (int j = 0; j < k; j++)
            ans += dp[v][j] * dp[u][k - j - 1];//������uΪ��㣻ans��ǰ�����ʹ��������֮ǰ����ԣ���ֹ�ظ���
        for (int j = 1; j <= k; j++)
            dp[u][j] += dp[v][j - 1];
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
        init();
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        ans = 0;
        dfs(1, 0, k);
        cout << ans << endl;
    return 0;
}

/*dp[u][x]��ʾ����u�ĳ�Ϊx��·����Ŀ��
Ϊ��ֹ�����ظ���Ҫ��������ǰ�����´�ǰ
*/
