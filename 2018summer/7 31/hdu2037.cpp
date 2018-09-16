#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int N,S[105],T[105];
pair<int,int>itv[105];

void solve(){

for(int i=0;i<N;i++)
{
    itv[i].first=T[i];
    itv[i].second=S[i];
}
sort(itv,itv+N);
int ans=0,t=0;
for(int i=0;i<N;i++)
{
    if(t<=itv[i].second){
        ans++;
    t = itv[i].first;}
}
printf("%d\n",ans);
}

int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        memset(T,0,sizeof(T));
        memset(S,0,sizeof(S));
        memset(itv,0,sizeof(itv));
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&S[i],&T[i]);
        }
        solve();
    }
    return 0;
}
