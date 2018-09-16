#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;


int dfs(ull n,int p){
    int q=1;ull k;
    for (int i=p-2;i>=0;i--){
        if (i) k=1ull<<(i-1);   //第i个串长度是1<<i-1
        else k=1;
        for (int j=0;j<q;j++){
            if (k<n) n-=k;
            else return dfs(n,i);
        }
        q++;
    }
    return p;    //最后一位是p
}
int solve(ull n){
    if (n==1)               //第一个串相比于其他的串有些特殊（1，1,2,4,8，
        return 0;
    n--;                       //不计算第一个0
    for (int i=0;;i++){
        ull t=1ull<<i;
        if (t<n) n-=t;
        else return dfs(n,i+1);   //i+1得n所在串（不包括第一个串）
    }
}
int main()
{
    ull n;
    while (cin>>n&&n){
       cout<<solve(n)<<endl;
    }
}
