#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n;
int d[maxn];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        printf("%d %d\n",d[2]-d[1],d[n]-d[1]);
        for(int i=2;i<n;i++)
        {
            int ans1=min(d[i]-d[i-1],d[i+1]-d[i]);
            int ans2=max(d[i]-d[1],d[n]-d[i]);
            printf("%d %d\n",ans1,ans2);
        }
        printf("%d %d\n",d[n]-d[n-1],d[n]-d[1]);
    }
    return 0;
}
