#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int p, m, n;
int ans;
int main() {

    while(cin>>p>>n>>m){
        if(p == 0 && m == 0 && n == 0)
            break;
        ans=p>m*n?p:m*n;
        cout<<ans<<endl;
    }
    return 0;
}