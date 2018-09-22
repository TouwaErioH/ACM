#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int n,m,u[maxn+10],v[maxn+10];

int main()
{
    scanf("%d%d",&n,&m);
    if((n-1)>m){puts("Impossible");return 0;}
      if(n==1&&m)
    {
        cout<<"Impossible"<<endl;    //n==1,m==1的时候wrong output format Output file not found: "output.fd0138e687.txt"

        //不知道为啥
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        u[m]=i;v[m--]=i-1;
    }

    for(int i=3;i<=n&&m;i++)
        for(int j=i-2;j&&m;j--)
        if(gcd(i,j)==1) u[m]=i,v[m--]=j;
    if(m)
    {
        puts("Impossible");return 0;
    }
    puts("Possible");
    for(int i=1;u[i];i++)
        printf("%d %d\n",u[i],v[i]);
    return 0;
}

//typ的解法http://codeforces.com/contest/1009/submission/42198154  素数分布定理
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
bool vis[MAXN];
LL phi[MAXN];
vector<int> prime;
void init() {
    int m = sqrt(MAXN + 0.5);
    prime.push_back(1);
    for(int i = 2; i <= m; ++i) if(!vis[i])
        for(int j = i * i; j < MAXN; j += i) vis[j] = true;
    for(int i = 2; i < MAXN; ++i) if(!vis[i]) prime.push_back(i);
    phi[1] = 1;
    for(int i = 2; i < MAXN; ++i) if(!phi[i])
        for(int j = i; j < MAXN; j += i) {
            if(!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    phi[1] = 0;
    for(int i = 1; i < MAXN; ++i) phi[i] += phi[i-1];
    //cout << prime.size() << endl;
}
inline gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
vector<pair<int, int>> ans;
int main() {
    init();
    //cout << phi[MAXN - 1];
    int n, m;
    cin >> n >> m;
    if(phi[n] < m || m < n - 1) {
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    if(n <= 5000) {
        for(int i = 1; m && i <= n; ++i)
            for(int j = i + 1;m && j <= n; ++j)
                if(gcd(i, j) == 1) {
                    ans.emplace_back(i, j);
                    --m;
                }
    }
    else {
        for(int i = 2; i <= n; ++i) ans.emplace_back(1, i), --m;
        for(int i = 1; m && i < prime.size() && prime[i] < n; ++i)
            for(int j = i + 1; m && j < prime.size() && prime[j] < n; ++j) {
                ans.emplace_back(prime[i], prime[j]);
                --m;
            }
    }
    for(auto x: ans) printf("%d %d\n", x.first, x.second);
}*/
