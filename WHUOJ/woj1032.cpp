// 按行/列翻转使得和最大
//按行递归
#include<iostream>
#include<cstdio>
using namespace std;

int m,n,ans;
int mapp[11][3001];

int maxm;

void dp(int t){
    int temp = 0;
    if(t<m){
        dp(t+1);
        if (ans ==maxm) return ;

        for(int j=0;j<n;j++)
            mapp[t][j]=!mapp[t][j];

        dp(t+1);

        if(ans == maxm) return ;

        for(int j=0;j<n;j++) //还原
            mapp[t][j]=!mapp[t][j];
    }
    else{
    int tmplinesum,sum=0;
    for(int i=0;i<n;i++){
        tmplinesum = 0;
        for(int j=0;j<m;j++)
            tmplinesum+=mapp[j][i];
        tmplinesum = m-tmplinesum>tmplinesum?m-tmplinesum:tmplinesum;
        sum+=tmplinesum;
    }
        temp = sum;
        ans=ans>temp?ans:temp;
        return ;
    }

}

int main(){
    while(cin>>m>>n){
        maxm=m*n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>mapp[i][j];
        ans=0;
        dp(1);
        cout<<ans<<endl;
    }
    return 0;
}