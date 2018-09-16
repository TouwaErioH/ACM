#include <iostream>
#include <cstdio>
#define MAX_N 150000+5
using namespace std;
int par[MAX_N];
int ran[MAX_N];

void init(int n){
   for(int i=0;i<n;i++){
       par[i]=i;
       ran[i]=0;
   }
}
int find_father(int x){
   if(x==par[x]){
       return x;
   }else{
       return par[x]=find_father(par[x]);
   }
}
void unite(int t1,int t2){
   int f1=find_father(t1);
   int f2=find_father(t2);
   if(f1==f2){
       return ;
   }
   if(ran[f1]<ran[f2]){
       par[f1]=f2;
   }else{
       par[f2]=f1;
       if(ran[f1]==ran[f2]){
           ran[f1]++;
       }
   }
}

bool same(int x,int y){
    return find_father(x)==find_father(y);
}

int main()
{
    int n,k;
    int d,x,y;
    int ans=0;
    scanf("%d %d",&n,&k);
    init(n*3);
    for(int i=0;i<k;i++){
        scanf("%d%d%d",&d,&x,&y);
        if(x<=0||x>n||y<=0||y>n||d==2&&x==y){
            ans++;
            continue;
        }

        if(d==1){
            if(same(x,y+n)||same(x,y+2*n)){
                ans++;
                continue;
            }
            else{
                unite(x,y);
                unite(x+n,y+n);
                unite(x+2*n,y+2*n);
            }
        }

        else{
            if(same(x,y)||same(x,y+2*n)){
                ans++;
                continue;
            }
            else{
                unite(x,y+n);
                unite(x+n,y+2*n);
                unite(x+2*n,y);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
