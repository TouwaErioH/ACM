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
      ans[col] = 'A' + i;                  //直接按照字典序大小，从小到大枚举
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
char G[2][10][10]; //一个三维的数组存储两个矩阵
int vis[2][30],cnt[10],he[10]; //vis[i][j]表示第i个矩阵第j个字母是否访问，cnt是每一列的总数，he是后缀积
char Select[10][10],ans[10]; //select[i][j]表示第i行第j个字母
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
        for(int i = 0; i < 5; i++)  //找两个矩阵对应的列中相同的元素处理的很好，对每一列对两个矩阵一行一行的查找
        {
            memset(vis, 0, sizeof(vis));
            for(int j = 0; j < 2; j++)
            {
                for(int m = 0; m < 6; m++)
                    vis[j][ G[j][m][i] - 'A' ] = 1;
            }
            for(int j = 0; j < 26; j++)
            {
                if(vis[0][j] && vis[1][j])  //两个矩阵同一列都访问过了
                    Select[i][ ++cnt[i] ] = 'A' + j; //第i列第cnt[i]个放入这个字母
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
        k--; //因为考虑到k == 1的情况
        for(int i = 0; i < 5; i++)
        {
            int t = k / he[i + 1];
            ans[i] = Select[i][t + 1]; //对于每一个字母都是从1开始标号的，整除之后取下一个，就像k = 1时，每一列都得取第一个，对于最后一列的时候 t = 1，那就取第二个了，所以k--
            k = k % he[i + 1];
        }
        ans[5] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
*/
