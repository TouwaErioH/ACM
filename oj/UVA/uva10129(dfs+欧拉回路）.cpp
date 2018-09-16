#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100;

int T, n, G[maxn][maxn], c[maxn], in[maxn], out[maxn];
int vis[maxn];

void dfs(int u)
{
    vis[u] = 1;//���ʱ��
    for (int v =0; v < 26; v++)//��ĸ�ڵ�
        if (!vis[v] && G[u][v])
            dfs(v);//û�б����ʲ����������
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
            int r = s[0]-'a';//��
            int t = s[len-1] - 'a';//β
            G[r][t] = 1;//�������
            in[t]++;
            out[r]++;//����Ҫ������������ȱ�д����   t,rΪ��㣬����Ϊ��
            vis[r] = vis[t] = 0;//������Ϊδ����״̬
        }

        int flag = 0;
        int p = 0, cnt1 = 0, cnt2 =0,flag2=0;;
        for (int i = 0; i < 26; i++) {
                if (out[i] == in[i])
                    continue;//�������
                if (out[i] == in[i]+1) {
                    cnt1++;p = i;//��ʼ��
                    if(cnt1>1) break;
                }
                else if (in[i] == out[i] + 1){
                    cnt2++;//�����
                    if(cnt2>2) break;
                }
                else
                    {flag2=1;
                    break;
                    }//û������
        }
        if (flag2) {
            printf("The door cannot be opened.\n");
            continue;
        }
// ��������
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
