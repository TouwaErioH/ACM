#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f

using namespace std;
int d[55][55];
int cut[55];
bool visit[55][55];
int L,n;

int dp(int i,int j)
{
    if((j-i)<=1) return 0;
    if(visit[i][j]==true) return d[i][j];
    visit[i][j]=true;
    for(int k=i+1;k<j;k++)
        d[i][j]=min(d[i][j],dp(i,k)+dp(k,j)+(cut[j]-cut[i]));
    return d[i][j];
}

int main()
{
    while(cin>>L&&L)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&cut[i]);
        }
        cut[0]=0;
        cut[n+1]=L;
        memset(visit,false,sizeof(visit));
        memset(d,INF,sizeof(d));
        int ans=dp(0,n+1);
        cout<<"The minimum cutting is "<<ans<<"."<<endl;
    }
    return 0;
}
