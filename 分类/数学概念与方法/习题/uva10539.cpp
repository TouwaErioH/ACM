#include<iostream>
#include<cmath>
typedef long long LL;
using namespace std;
const int maxn=1e6+5;

LL prime[maxn];
bool isprime[maxn];
int num;
void eulerprime()
{
    int j;
    for(int i = 2; i <= maxn; i ++){
        if(!isprime[i])
            prime[num ++] = i;
        for(j  = 0; j < num; j ++){
            if(i * prime[j] > maxn)
                break;
            isprime[i * prime[j]] = true;
            if(i % prime[j] == 0)
                break;
        }
    }
}

LL solve(LL n)
{
    LL ans=0;
    for (int i=0;i<num&&prime[i]*prime[i]<=n;i++)
      ans+=log(n)/log(prime[i])-1;
    return ans;
}

int main(){
    eulerprime();
    int t;
	scanf("%d", &t);
	LL l,r;
	while (t--) {
		scanf("%lld%lld", &l, &r);
		LL ans = 0;
	ans=solve(r)-solve(l-1);
  		printf("%lld\n", ans);
 	}
return 0;
}

