#include<cstdio>
#include<iostream>
using namespace std;
const int mod=10056;
const int maxn=1000;
int C[maxn+1][maxn+1];
int f[maxn+1];

int main()
{
    int kase=0,n,t;
     for(int i = 0; i <= maxn; i++) {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
  }

       f[0] = 1;
  for(int i = 1; i <= maxn; i++) {
    f[i] = 0;
    for(int j = 1; j <= i; j++)
        f[i] = (f[i] + C[i][j] * f[i-j]) % mod;
  }

    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Case "<<++kase<<": "<<f[n]<<endl;
    }
    return 0;
}

