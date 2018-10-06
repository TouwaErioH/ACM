#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000010;
#define inf 0x3f3f3f3f
int n,m,k;
int a[maxn]={0,1,2,3},vis[maxn];
int main(){
    int t,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=4;i<=n;++i)
            a[i]=(a[i-1]+a[i-2]+a[i-3])%m+1;
        int ans=inf,s=1,temp=1,cnt=0;
        memset(vis,0,sizeof(vis));
        while(true){
            while(temp<=n&&cnt<k){
                vis[a[temp]]++;
                if(a[temp]<=k&&vis[a[temp]]==1) ++cnt;
                temp++;
            }
            if(cnt<k) break;
            ans=min(temp-s,ans);
            vis[a[s]]--;
            if(a[s]<=k&&vis[a[s]]==0) --cnt;
            s++;
        }
        printf("Case %d: ",++kase);
        if(ans==inf)
            printf("sequence nai\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
