#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 100000 + 5;
int bad[maxn];

void prime_factors(int n, vector<int>& primes) {
  int m = floor(sqrt(n) + 0.5);
  for(int i = 2; i <= m; i++) {
    if(n % i == 0) { // �µ�������
      primes.push_back(i);
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) primes.push_back(n);
}


int main() {
  int n, m, kase = 0;
  while(cin >> n >> m) {
    vector<int> primes;
    prime_factors(m, primes);
    memset(bad, 0, sizeof(bad));
    //n--;
    // ��c(n,0)~c(n,n)����Щ����m�ı���         //���ai��ϵ����C(n-1,i-1)
    for(int i = 0; i < primes.size(); i++) {
      int p = primes[i], e = 0; // C(n,0) = p^e
      int min_e = 0, x = m;
      while(x % p == 0) { x /= p; min_e++; }   //����ÿ�������ӵ�ָ��һ�����ж�
      // c(n,k)=c(n,k-1)*(n-k+1)/k
      for(int k = 1; k < n-1; k++) {
        x = n-1-k+1;
        while(x % p == 0) { x /= p; e++; }   //e����0������֮ǰ�Ľ��
        x = k;
        while(x % p == 0) { x /= p; e--; }
        if(e < min_e) bad[k+1] = 1;
      }
    }
    vector<int> ans;
    for(int k = 2; k < n; k++)
      if(!bad[k]) ans.push_back(k); // ��Ŵ�1��ʼ//m>=2������a1��an������
    cout << ans.size() << "\n";
    if(!ans.empty()) {
           cout << ans[0];
      for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
    }
    cout << "\n";
  }
  return 0;
}
