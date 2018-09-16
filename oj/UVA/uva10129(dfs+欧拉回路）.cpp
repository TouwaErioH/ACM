#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100;

int T, n, G[maxn][maxn], c[maxn], in[maxn], out[maxn];
int vis[maxn];

void dfs(int u)
{
    vis[u] = 1;//访问标记
    for (int v =0; v < 26; v++)//字母节点
        if (!vis[v] && G[u][v])
            dfs(v);//没有被访问并且有有向边
}

int main()
{
    char s[2000];
    scanf("%d", &T);
    while (T--) {
        memset(vis, 1, sizeof(vis));
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        scanf("%d", &n);

        for (int i =0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s);
            int r = s[0]-'a';//首
            int t = s[len-1] - 'a';//尾
            G[r][t] = 1;//有有向边
            in[t]++;
            out[r]++;//很重要！！！，出入度别写反了   t,r为结点，单词为边
            vis[r] = vis[t] = 0;//将其置为未访问状态
        }

        int flag = 0;
        int p = 0, cnt1 = 0, cnt2 =0,flag2=0;;
        for (int i = 0; i < 26; i++) {
                if (out[i] == in[i])
                    continue;//环的情况
                if (out[i] == in[i]+1) {
                    cnt1++;p = i;//起始点
                    if(cnt1>1) break;
                }
                else if (in[i] == out[i] + 1){
                    cnt2++;//其余点
                    if(cnt2>2) break;
                }
                else
                    {flag2=1;
                    break;
                    }//没有满足
        }
        if (flag2) {
            printf("The door cannot be opened.\n");
            continue;
        }
// 环或者是
        if (cnt1==1 &&cnt2 == 1 || cnt1==0 && cnt2==0)
            flag = 1;
        else
            flag = 0;

        if(flag){
        dfs(p);
        for (int i = 0; i < 26; i++)
            if(!vis[i])
                flag = 0;
         }

        if (flag) printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}
