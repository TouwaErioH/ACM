#include<iostream>
using namespace std;
const int maxn=1005,mod=1000000007;
int ans[maxn]={0,1};
void init(){
    for(int i=1;i<maxn;++i)
        for(int j=1;j<i;++j){
            if((i-1)%j!=0)
                continue;
            ans[i]+=ans[j]%mod;
            ans[i]%=mod;
        }
}
int main(){
    init();

    int t=0,n;
    while(cin>>n)
        cout<<"Case "<<++t<<": "<<ans[n]<<endl;
    return 0;
}
