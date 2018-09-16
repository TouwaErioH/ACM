#include<iostream>
#include<cstdio>

using namespace std;
int ans[31], g[31];
int main()
{
    int n;
    ans[0] = ans[1] = ans[2] = 0;
    g[0] = 1; g[1] = 2; g[2] = 4;
     for(int n = 3; n <= 30; n++) {
    ans[n] = 1 << (n-3);
    for(int i = 2; i <= n-2; i++)
      ans[n] += g[i-2] * (1 << (n-i-2));
    g[n] = (1<<n) - ans[n];
  }
    while(scanf("%d",&n)==1&&n)
    cout<<ans[n]<<endl;
        return 0;
}
