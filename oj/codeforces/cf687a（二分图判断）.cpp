#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int col[maxn];
vector<int>v[maxn];
bool dfs( int u ,int color )
{
    col[u] = color;
    for(int i = 0; i<v[u].size(); i++)
    {
        int t = v[u][i];
        if(col[t]==color)
            return false;
        if(col[t]==0&&!dfs(t,-color))
            return false;
    }
    return true;
}
int main()
{
     memset(col,0,sizeof(col));
    int n ,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i<=m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int flag = true;
    for(int i = 1; i<=n; i++)
    {
        if(col[i]==0)
        {
            if(!dfs(i,1))
            {
                flag = false;
                break;
            }
        }
    }
    if(!flag)
        cout<<"-1"<<endl;
    else
    { int cnt = 0;
        for(int i = 1; i<=n; i++)
        {
            if(col[i]==1)
                cnt++;
        }
        printf("%d\n",cnt);
        for(int i = 1;i<=n;i++)
        {
            if(col[i]==1)
                printf("%d ",i);
        }
        printf("\n");
        printf("%d\n",n-cnt);
        for(int i = 1;i<=n;i++)
        {
             if(col[i]==-1)
             {
                 printf("%d ",i);
             }
        }
        printf("\n");
    }
    return 0;
}
