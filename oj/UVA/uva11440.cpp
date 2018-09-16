#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10000002;
bool IsPrime[maxn];
int Prim[maxn];
long long phifac[maxn];
const int MOD=100000007;
void  euler_prime(int n){
    int num = 0, j;
    for(int i = 2; i <= n; i ++){
        if(!IsPrime[i])
            Prim[num ++] = i;
        for(j  = 0; j < num; j ++){
            if(i * Prim[j] > n)
                break;
            IsPrime[i * Prim[j]] = true;
            if(i % Prim[j] == 0)
                break;
        }
    }
}


int main()
{
    euler_prime(maxn);
    int n,m;
    phifac[1]=phifac[2]=1;
    for(int i=3;i<=10000000;i++)
    {
       phifac[i]=(long long)phifac[i-1]*(IsPrime[i]==false?i-1:i)%MOD;
    }
    while(cin>>n>>m&&n)
    {
        long long ans=phifac[m];
        for(int i=m+1;i<=n;i++) ans=(long long)ans*i%MOD;
        cout<<(ans-1)%MOD<<endl;
    }
    return 0;
}
