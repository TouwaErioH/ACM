#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, c1, c2;
const int maxn = 10010;
const int INF = 0x3f3f3f3f;
vector<int> sons[maxn];
int dp[maxn][4];

void dfs(int u, int fa)
{
    dp[u][0] = dp[u][3] = 0;
    dp[u][1] = c1;
    dp[u][2] = c2;
    int min_A = INF, sum = 0;
    for (int i = 0; i < sons[u].size(); i++)        //ѡ1Ϊ������������Ҷ�������ѭ��
    {
        int v = sons[u][i];
        if (v == fa) continue;
        dfs(v, u);
        int min_of_t = min(min(dp[v][0], dp[v][1]), dp[v][2]);

        dp[u][0] += dp[v][1];
        dp[u][1] += min_of_t;
        dp[u][2] += min(min_of_t, dp[v][3]);
        dp[u][3] += min_of_t;

        sum += min_of_t;
        min_A = min(min_A, dp[v][2] - min_of_t);
    }
    sum += min_A;
    dp[u][1] = min(dp[u][1], sum);
}

int main()
{
    while (scanf("%d%d%d", &n, &c1, &c2)==3&&c2)
    {
        for (int i = 1; i <= n; i++)
            sons[i].clear();
        int u, v;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d",&u, &v);
            sons[u].push_back(v);
            sons[v].push_back(u);
        }
        dfs(1, -1);
        int ans = min(min(dp[1][0], dp[1][1]), dp[1][2]);
        printf("%d\n", ans);
    }
    return 0;
}
/*
dp[u][0]:uû�а�װװ��,��u���ӽڵ��µı߶�������
dp[u][1]:u��װװ��A
dp[u][2]:u��װװ��B
dp[u][3]:uû�а�װװ��,��v���Բ���װװ�� ���Ե�uΪ����������������ı߶������ǣ�����u��������ı߲�һ��������

dp[u][0]=Sum( min(dp[v][1],dp[v][2]) );
dp[u][1]=min( C1+Sum( min(dp[v][0],dp[v][1],dp[v][2]) ),Sum( min(dp[v][2],dp[v][1],dp[v][0]) ��������һ���ӽڵ�ѡ��B)���γ�A��Ч�� )
dp[u][2]=C2+Sum( min(dp[v][0],dp[v][1],dp[v][2],dp[v][3]) )
dp[u][3]=Sum(min(dp[v][0],dp[v][1],dp[v][2]))
*/
