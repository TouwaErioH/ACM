#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int par[maxn];

void init(int n){
   for(int i=0;i<n;i++){
       par[i]=i;
   }
}
int find_par(int x)
{
	return par[x] != x ? par[x] = find_par(par[x]) : x;
}

int main()
{
	int x, y;
	while(scanf("%d", &x)&&x!=-1)
	{
		init(maxn);
		int ans = 0;
		while(x != -1)
		{
			scanf("%d", &y);
			x = find_par(x);   //思路，树（形成环则不可），两个点一条边，若两点都可以连到树上则形成环不可；
			y = find_par(y);   //递推，一个没问题，2种，两个没问题3/4种，4新建一个集合；3个，若下一个两个元素均在集合里则不可；有一个在则为4个元素，之后重复这个过程
			if(x == y) ans++;
			else par[x] = y;
			scanf("%d", &x);
		}
		printf("%d\n", ans);
	}
	return 0;
}
