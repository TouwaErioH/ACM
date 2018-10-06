#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;

const int maxn = 100005;
int s[maxn];

int main()
{
	int n, d;
	while (scanf("%d%d%*c", &n, &d) && n) {
		int t = 0;
		int a;
		d = n - d;
		for (int i = 0; i < n; i++) { //位数相同，贪心策略为最高位最大
			a = getchar() - '0';
			while (t && t + n - i > d && a > s[t - 1]) {
				t--;
			}
			if (t < d) {
				s[t++] = a;
			}
		}
		for (int i = 0; i < t; i++) {
			printf("%d", s[i]);
		}
		printf("\n");
	}

	return 0;
}
