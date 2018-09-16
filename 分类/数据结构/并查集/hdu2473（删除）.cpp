#include <cstdio>
#include <cstring>
#include<iostream>
#include <algorithm>
using namespace std;

int par[2000005];
int vis[2000005];
int n, m, id;
char str[5];

void init(int n)
{
		for(int i = 0; i < n; i++)
			par[i] = i + n;//虚拟父节点
		for(int i = n; i <= n + n + m; i++)//n+n+m: 最多可能删除m个节点
			par[i] = i;
}

int findpar(int x){
	if(x == par[x])
		return x;
	else return par[x] = findpar(par[x]);
}

void unite(int x, int y){
	int fx = findpar(x);
	int fy = findpar(y);
	if(fx != fy)
		par[fy] = fx;
}

void del (int x){
	par[x] = id ++;
}

int main (){
	int a,b,c;
	int k = 1;
	while(scanf("%d%d", &n, &m)&&n){
			init(n);
            id = 2*n;
			while(m--){
			scanf("%s", &str);
			if(str[0] == 'M'){
				scanf("%d%d", &a, &b);
				 unite(a,b);
			}
			else{
				scanf("%d", &c);
				del(c);
			}
		}
		int ans = 0;
		fill(vis,vis+2000005,0);
		//for(int i=0;i<=2000004;i++)       //必须整组而不是n+n+m，否则会影响下一组的判断
           // vis[i]=0;
		//memset(vis, 0 ,sizeof(vis));
		for(int i = 0; i < n; ++i){
			int x = findpar(i);
			if(!vis[x]){
				ans++;
				vis[x] = 1;
			}
		}
		printf("Case #%d: %d\n", k++, ans);
	}
	return 0;
}
