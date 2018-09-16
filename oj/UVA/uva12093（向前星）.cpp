#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e4+100;
struct Edge{
    int to,next;
}e[N*2];

int tot,head[N],n,C1,C2,dp[N][4];

int gmin(int x,int y,int z){
    if(x>y) x=y;
    if(x>z) x=z;
    return x;
}

void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}

void addedge(int from,int to){
    e[tot]=(Edge)
    {to,head[from]};
    head[from]=tot++;
}

void dfs(int u,int pre){
    dp[u][0]=0,dp[u][1]=C1,dp[u][2]=C2,dp[u][3]=0;
    int flag=0,sum=0,mi=INF;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(v==pre)  continue;
        dfs(v,u);
        dp[u][0]+=min(dp[v][1],dp[v][2]);
        dp[u][1]+=gmin(dp[v][0],dp[v][1],dp[v][2]);
        dp[u][2]+=min(gmin(dp[v][0],dp[v][1],dp[v][2]),dp[v][3]);
        dp[u][3]+=gmin(dp[v][0],dp[v][1],dp[v][2]);
        int x=gmin(dp[v][0],dp[v][2],dp[v][1]);
        sum+=x;
        mi=min(mi,dp[v][2]-x);  //保证至少有一个[V][2]，且不断更新选那个最小的
    }
    sum+=mi;
    dp[u][1]=min(dp[u][1],sum);
}

int main(){
    while(scanf("%d%d%d",&n,&C1,&C2)==3){
        if(n==0&&C1==0&&C2==0)  break;
        int u,v;
        init();
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1,0);
        printf("%d\n",gmin(dp[1][0],dp[1][1],dp[1][2]));
    }
    return 0;
}
/*
dp[u][0]:u没有安装装置,且u的子节点下的边都被覆盖
dp[u][1]:u安装装置A
dp[u][2]:u安装装置B
dp[u][3]:u没有安装装置,且v可以不安装装置          以点u为根的子树的子树里的边都被覆盖，但是u和子树间的边不一定被覆盖

dp[u][0]=Sum( min(dp[v][1],dp[v][2]) );
dp[u][1]=min( C1+Sum( min(dp[v][0],dp[v][1],dp[v][2]) ),Sum( min(dp[v][2],dp[v][1],dp[v][0]) 且至少有一个子节点选择B) )
dp[u][2]=C2+Sum( min(dp[v][0],dp[v][1],dp[v][2],dp[v][3]) )
dp[u][3]=Sum(min(dp[v][0],dp[v][1],dp[v][2]))
*/

