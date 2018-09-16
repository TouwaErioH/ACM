#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

int dp[maxn],ans1,ans2,sum,root;
vector<int> sons[maxn];

void dfs(int u){
    for(int i=0; i<sons[u].size(); i++){
        dfs(sons[u][i]);
        dp[u] += dp[sons[u][i]];
    }

    if(dp[u]==sum/3 && u!=root){
        if(!ans1)
            { ans1=u; dp[u]=0;}
        else if(!ans2)
            { ans2=u; return ;}
    }
}

int main()
{
    int n,x;
    cin >> n;
    ans1=0,ans2=0;
    sum = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&dp[i]);
        if(x==0) root = i;
        else sons[x].push_back(i);
        sum += dp[i];
    }
    if(sum%3)
      {
        puts("-1");
        return 0;
      }

    dfs(root);
    if(!ans1 || !ans2)
         {puts("-1");
         return 0;
         }
    else
        cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
/*ֱ������dfs����һ�ҳ���һ��sum/3��Ȼ������������㣬
Ȼ����dfsһ�Σ�ֱ�Ӻ��ӵ�ǰһ��sum/3���ҳ��ڶ���sum/3��������ҳ�������������ܾ�-1��
*/
