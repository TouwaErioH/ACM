#include<iostream>
using namespace std;
const int maxn=1300000;
int p[maxn];
bool np[maxn]={true,true};

void init(int n){
int num=0;
 for(int i=2;i<n;i++){
        if(!np[i])
            p[num++]=i;
        for(int j=0;j<n&&i*p[j]<maxn;j++){
            np[i*p[j]]=1;
            if(i%p[j]==0) break;
        }
    }

}
int main(){
int n=0;
   init(maxn);
    while(cin>>n&&n){
        if(!np[n]){
            cout<<"0"<<endl;
            continue;
        }
        int i=n,j=n;
        while(np[i]) i--;
        while(np[j]) j++;
        cout<<j-i<<endl;
    }
    return 0;
}