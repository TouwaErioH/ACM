#include<iostream>
#include<algorithm>
using namespace std;


long long cal(int q,int p,int n)
{
    return (long long)(q+q-p*n)*(n+1)/2;
}

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
    int i = 1;
    long long ans = 0;
    while(i <= n) {
      int q = k % i, p = k / i;
      int cnt = n - i;
      if(p > 0) cnt = min(cnt, q / p);
      ans += cal(q, p, cnt);
      i += cnt + 1;
    }
    cout << ans << endl;
    }
    return 0;
}















