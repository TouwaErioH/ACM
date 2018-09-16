#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

 
int main(){
 
	int n;
	while (scanf("%d",&n)&&n){
		double xa,ya,xb,yb;
		scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
		
		double L = 0.0;
		double s = 0.0, len;
 
		for (int i = 0; i < n; ++i){
			scanf("%lf",&len);
			L += len;
			s += len * len/ 2;
		}
 
		double k1 = ya / xa, k2 = yb / xb;
		if (k1 > k2){
			swap(k1,k2);
		}
 
		double x1 = (k2 + 1) / (k2 - k1) * L;
		double x2 = (k1 + 1) / (k2 - k1) * L;
		double y1 = k1 * x1, y2 = k2 * x2;
 
		double ans = abs(x1 * y2 - x2 * y1) / 2 - s; 
		printf("%.3lf\n",ans);
}
	return 0;
}