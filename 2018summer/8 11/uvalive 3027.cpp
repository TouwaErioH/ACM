#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 20005;
int par[maxn], dep[maxn];

void init(int n){
for(int i=0; i <= n; i++) { par[i] = i; dep[i] = 0; }
}

int find_par(int x)
{
	if(par[x] != x)
	{
		int pare = find_par(par[x]);
		dep[x] += dep[par[x]];
		return par[x] = pare;
	}
	else return x;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, i, j;
		char cmd[9];
		scanf("%d", &n);
		init(n);
		while(scanf("%s", cmd) && cmd[0] != 'O')
		{
			if(cmd[0] == 'E')
			{
				scanf("%d", &i);
				find_par(i);
				printf("%d\n", dep[i]);
			}
			if(cmd[0] == 'I')
			{
				scanf("%d %d", &i, &j);
				par[i] = j; dep[i] = abs(i - j) % 1000;
			}
		}
	}
	return 0;
}
