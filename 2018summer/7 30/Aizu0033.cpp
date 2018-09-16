#include<bits/stdc++.h>
using namespace std;
int x[15],l[15],r[15];
int flag;
void dfs(int i,int j,int k)
{
    if(i>10){
    		flag=1;
    		return;
    	}
    if(x[i]>l[j-1]){
    		l[j]=x[i];dfs(i+1,j+1,k);
    	}
    if(x[i]>r[k-1]){
    		r[k]=x[i];dfs(i+1,j,k+1);
    	}
    }
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=10;++i){
            scanf("%d",&x[i]);
        }
        flag=0;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        dfs(1,1,1);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    	}
    	return 0;
    }
