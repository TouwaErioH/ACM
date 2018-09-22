#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



const int maxn=500005;

ll a[maxn];

int main(){
    ll n,sum=0; cin>>n;
    ll minn=0x3f3f3f3f,maxx=-0x3f3f3f3f;
    for(ll i=0;i<n;i++){
        cin>>a[i]; sum+=abs(a[i]);
        minn=min(minn,a[i]); maxx=max(maxx,a[i]);
    }
    if(n==1){ cout<<a[0]<<endl; return 0; }                  //特殊情况别忘了啊
    if(n==2){ cout<<max(a[0]-a[1],a[1]-a[0])<<endl; return 0; }
    if(minn>0) sum-=2*minn;
    else if(maxx<0) sum-=2*abs(maxx);
    cout<<sum<<endl; return 0;
}
