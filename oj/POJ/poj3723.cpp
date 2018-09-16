#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int father[50005];
int n,m,r;
struct node{
    int u,v,cost;
}edge[50005];

int cmp(struct node a,struct node b){
    return a.cost<b.cost;
}

int found(int x){
    if(x!=father[x])
    father[x]=found(father[x]);
    return father[x];
}

void unite(int x,int y){
    x=found(x);
    y=found(y);
    if(x==y)
    return;
    father[x]=y;
}

bool same(int x,int y){
    return found(x)==found(y);
}

int kruskal(){
    int i,ans;
    struct node e;
    ans=0;
    sort(edge,edge+r,cmp);
    for(i=0;i<r;i++){
        e=edge[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            ans+=e.cost;
        }
    }
    return ans;
}                                           //kruskal模板
int main(){                                 //将每个人的费用取反，则变为求最小生成森林
    int t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&r);
        for(i=0;i<50005;i++)
        father[i]=i;
        for(i=0;i<r;i++){
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].cost);
            edge[i].v+=n;                   //并查集，将女兵的编号加N
            edge[i].cost*=-1;
        }
        printf("%d\n",10000*(n+m)+kruskal());
    }
    return 0;
}
