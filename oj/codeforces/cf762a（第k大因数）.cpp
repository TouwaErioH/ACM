#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
vector<int>x;
int main()
{
    ll n;
    int k;
    scanf("%lld%d",&n,&k);
    for(ll i=1;i*i<=n;++i)
        if(n%i==0) x.push_back(i);
    if(x.size()>=k) printf("%d",x[k-1]);
    else
    {
        int l=x.size(),sf=(ll)x[l-1]*x[l-1]==n;
        if(k>l*2-sf) printf("-1");
        else printf("%lld",n/(ll)x[2*l-k-sf]);
    }
    return 0;
}
