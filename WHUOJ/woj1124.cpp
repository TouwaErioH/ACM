// 网络流  https://blog.csdn.net/gauss_acm/article/details/43795611


#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

const int maxn=1110;
#define inf 0x3f3f3f3f

int myscore[maxn];

int father[maxn];
int q[maxn];
int d[maxn];
int cnt,source,t,n,m;

struct edge{
    int to,next,capacity;
}p[maxn*maxn*2];


void addedge(int a,int b,int c){
    p[cnt].to=b;
    p[cnt].next=father[a];
    p[cnt].capacity=c;
    father[a]=cnt++;
}

void insert(int a,int b,int c){
    addedge(a,b,c);
    addedge(b,a,0);
}

bool mybfs(){
    memset(d,-1,sizeof d);
    int s=0,e=-1;
    q[++e]=source;
    d[source]=0;
    while(s<=e){
        int u=q[s++];
        for(int i=father[u];i!=-1;i=p[i].next){
            int v=p[i].to;
            if(d[v]==-1&&p[i].capacity){
                d[v]=d[u]+1;
                q[++e]=v;
            }
        }
    }
    return d[t]!=-1;
}

int mydfs(int u,int alpha){
    if(u==t) 
        return alpha;
    int w,used=0;
    for(int i=father[u];i!=-1&&used<alpha;i=p[i].next){
        int v=p[i].to;
        if(p[i].capacity&&d[v]==d[u]+1){
            w=mydfs(v,min(alpha-used,p[i].capacity));
            used+=w;
            p[i].capacity-=w;
            p[i^1].capacity+=w;
        }
    }
    if(!used) d[u]=-1;
    return used;
}

int dinicroad(){
    int ans=0;
    source=0,t=m+n+1;
    while(mybfs())
        ans+=mydfs(source,inf);
    return ans;
}

bool flag;
int ans;
int main()
{
    int a,b;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            cin>>myscore[i];
        ans=0;
        cnt=0;
        memset(father,-1,sizeof father);
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            if(a>b){
                a=a^b;
                b=b^a;
                a=a^b;
            }
            if(b==n) 
                myscore[n]+=2;
            else{
                ans++;
                insert(0,i,2);
                insert(i,m+a,2);
                insert(i,m+b,2);
            }
        }
        flag=true;
        for(int i=1;i<n;i++)
            if(myscore[i]>=myscore[n]){
                flag=false;
                break;
            }
        if(!flag) 
            cout<<"NO"<<endl;
        else{
            for(int i=1;i<n;i++)
                insert(m+i,m+n+1,myscore[n]-1-myscore[i]);
            if(dinicroad()==ans*2) 
                cout<<"YES"<<endl;
            else 
                cout<<"NO"<<endl;
        }
    }
	return 0;
}