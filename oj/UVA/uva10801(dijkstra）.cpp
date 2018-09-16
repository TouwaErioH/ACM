#include<cstdio>
#include<cstring>
#include<cmath>
const int N = 105;
const int INF = 0x3f3f3f3f;
int d[N];
int cost[5];
int v[N];
int n,k;
int reach[N];
int g[N][N];
char ch;
void build(int l ,int num) {
	int temp;
	for (int i = 0 ; i < num ;i++) {
		for (int j = i ; j < num ;j++) {
			temp = (reach[j] - reach[i]) * cost[l];
			if(temp < g[reach[i]][reach[j]]) {
				g[reach[i]][reach[j]] = temp;
				g[reach[j]][reach[i]] = temp;
			}
		}
	}
}
void dijkstra() {
	memset(v , 0 , sizeof(v));
	for (int i = 0 ; i <= 100 ;i++) {
		d[i] = (i == 0 ? 0 : INF);
	}

	for (int i = 0 ; i <= 100 ;i++) {
		int x ;
		int m = INF;
		for (int j = 0 ; j <= 100 ;j++) {
			if (!v[j] && d[j] < m)
				m = d[x = j];
		}
		v[x] = 1;
		for (int j = 0 ; j <= 100 ;j++) {
			if (d[j] > d[x] + g[x][j] + 60)
				d[j] = d[x] + g[x][j] + 60 ;
		}
	}
}
int main () {
	while(~scanf("%d%d",&n,&k)) {
		for (int i = 0 ; i <= 100 ;i++) {
			for (int j = 0 ; j <= 100 ;j++) {
				g[i][j] = INF;
			}
		}
		for (int i = 0 ; i < n ;i++) {
			scanf("%d",&cost[i]);
		}
		for (int i = 0 ; i < n ;i++) {
			int  num = 0;
			memset(reach , 0 ,sizeof(reach));
			do {
				scanf("%d",&reach[num++]);
			}while((ch = getchar()) != '\n');
			build(i,num);
		}
		dijkstra();
		if(k == 0 ) {
			printf("0\n");
			continue;
		}
		if (d[k] >= INF)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",d[k] - 60);

	}
}
