// 冒泡排序交换次数为逆序对个数
#include<map>
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=4005;
int mapp[maxn];
int T,n,ans;
int temp;
int main() {
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++)
            cin>>mapp[i];
    for(int k=0;k<n-1;k++)
        for(int p=k+1;p<n;p++)
            if(mapp[k]>mapp[p])
            {
               // temp=mapp[k];
               // mapp[k]=mapp[p];
              //  mapp[p]=temp;
                ans++;
            }
            cout<<ans<<endl;
    }
    return 0;
}
