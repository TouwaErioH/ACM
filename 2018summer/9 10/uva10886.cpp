#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

typedef long double LL;

unsigned long long seed;
long double gen() {
	static const long double Z = (long double)1.0 / (1LL << 32); seed >>= 16;
	seed &= (1ULL << 32) - 1;
	seed *= seed;
	return seed * Z;
}


int main(){
	LL T;
	cin >> T;
int kase=0;
	while(T--){
		LL n;
		cin >> n >> seed;
		LL sum1 = 0, sum2 = 0,ave=0;
		for (int i = 0; i < n; i++){
			LL temp = gen();
			sum1 += temp*temp;
			sum2 += temp;
		}
		ave = sum2 / n;
		LL ans = sum1 / n - ave*ave;
printf("Case #%d: %.5Lf\n",++kase,sqrt(ans));
		//cout << "Case #" << ++kase << ": "<<fixed<<setprecision(5)<< sqrt(ans) << endl;
		//cout << defaultfloat;
	}
}
