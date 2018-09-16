#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dp[6005][2],fa[6005],vis[6005][2];
vector<int> sons[6005];

int dp_tree(int u, int k) {
    if(!vis[u][k]){
                vis[u][k]=1;
     if(k==1)
    {
        if(sons[u].size()==0)
           return dp[u][k];
       for(int i = 0; i < sons[u].size(); i++) {
         int v = sons[u][i];
         dp[u][1] += dp_tree(v, 0);
        }
    }
      else
    {
        if(sons[u].size()==0)
          return dp[u][k];
         for(int i = 0; i < sons[u].size(); i++)
         {
            int v = sons[u][i];
            dp[u][0] += max(dp_tree(v, 0), dp_tree(v, 1));
         }
    }
    }
  return dp[u][k];
}

  int main()
{
    int f,c,root=0;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i][1]=fa[i]=vis[i][0]=vis[i][1]=0;
        }
        for(int i=1; i<=n; i++)
            scanf("%d",&dp[i][1]);
    for(int i = 1; i <=n; i++)
        sons[i].clear();
    for(int i = 0; i < n; i++) {
      cin >> c >> f;
      if(c==0)
         break;
      sons[f].push_back(c);
      fa[c]=f;
    }
    root=1;
    while(fa[root]!=0)
       root=fa[root];

        printf("%d\n",max(dp_tree(root, 0), dp_tree(root, 1)));
    }
    return 0;
}
