#include<cstdio>
#include<cstring>
using namespace std;

int k, cnt;
char p[2][6][9], ans[9];

bool dfs(int col) {
  if(col == 5) {
    if(++cnt == k) {
      ans[col] = '\0';
      printf("%s\n", ans);
      return true;
    }
    return false;
  }
  bool vis[2][26];
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 6; j++)
      vis[i][p[i][j][col] - 'A'] = true;
  for(int i = 0; i < 26; i++)
    if(vis[0][i] && vis[1][i]) {
      ans[col] = 'A' + i;                  //ֱ�Ӱ����ֵ����С����С����ö��
      if(dfs(col+1)) return true;
    }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &k);
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 6; j++)
        scanf("%s", p[i][j]);
    cnt = 0;
    if(!dfs(0)) printf("NO\n");
  }
  return 0;
}


/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int k;
char G[2][10][10]; //һ����ά������洢��������
int vis[2][30],cnt[10],he[10]; //vis[i][j]��ʾ��i�������j����ĸ�Ƿ���ʣ�cnt��ÿһ�е�������he�Ǻ�׺��
char Select[10][10],ans[10]; //select[i][j]��ʾ��i�е�j����ĸ
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &k);
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 6; j++)
                scanf("%s", G[i][j]);
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < 5; i++)  //�����������Ӧ��������ͬ��Ԫ�ش���ĺܺã���ÿһ�ж���������һ��һ�еĲ���
        {
            memset(vis, 0, sizeof(vis));
            for(int j = 0; j < 2; j++)
            {
                for(int m = 0; m < 6; m++)
                    vis[j][ G[j][m][i] - 'A' ] = 1;
            }
            for(int j = 0; j < 26; j++)
            {
                if(vis[0][j] && vis[1][j])  //��������ͬһ�ж����ʹ���
                    Select[i][ ++cnt[i] ] = 'A' + j; //��i�е�cnt[i]�����������ĸ
            }
        }
        he[5] = 1;
        for(int i = 4; i >= 0; i--)
        {
            he[i] = cnt[i] * he[i + 1];
        }
        if(k > he[0])
        {
            printf("NO\n");
            continue;
        }
        k--; //��Ϊ���ǵ�k == 1�����
        for(int i = 0; i < 5; i++)
        {
            int t = k / he[i + 1];
            ans[i] = Select[i][t + 1]; //����ÿһ����ĸ���Ǵ�1��ʼ��ŵģ�����֮��ȡ��һ��������k = 1ʱ��ÿһ�ж���ȡ��һ�����������һ�е�ʱ�� t = 1���Ǿ�ȡ�ڶ����ˣ�����k--
            k = k % he[i + 1];
        }
        ans[5] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
*/
