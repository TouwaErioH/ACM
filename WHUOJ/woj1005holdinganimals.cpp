#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=10005;
int value[maxn];
int sizee[maxn];
int final[100005];

// memset(final,0,sizeof(int)*4); 注意memset是字节为单位，只能赋值0。比如int 4字节0000 0X01010101.
//速度慢 另外注意一个字节2个16进制数
// memset(a,0x3f,sizeof(a))

int main(){
    int n=0,noah=0;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>sizee[i]>>value[i];
        }
    cin>>noah;
    for(int i=0;i<=noah;i++) final[i]=0;  
    for(int i=0;i<n;i++)
        for(int j=noah;j>0;j--)   //倒序理解就是01背包只有一件，前i-1件已经判断完了，只判断这一件，在比较小的情况下放不影响在比较大的情况放
            if(j>=sizee[i])         //final可行因为如果小的能放大的也能放。
                final[j]=max(final[j],final[j-sizee[i]]+value[i]);
        cout<<final[noah]<<endl;
    }
    return 0;
}