#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
char maps[1005][1005];
int  step[1005][1005];
int  d[4][2] = {1,0,-1,0,0,1,0,-1};
#define inf 1000005
typedef struct nodep{
	int x,y,s,f;            //s表示时间，f表示状态
}point;
point Q[1000005];    //储存火和人

void bfs( int n, int m )
{
    point joe;
	int move = 0,save = 0;
	for ( int i = 0 ; i < n ; ++ i )    //初始化
	for ( int j = 0 ; j < m ; ++ j ) {
		if ( maps[i][j] == 'J' )
			joe.x=i,joe.y=j,joe.s=0,joe.f=0;
		if ( maps[i][j] == 'F' )
			Q[save ++] = { i, j, 0, 1 };
		step[i][j] = inf;
	}

	step[joe.x][joe.y] = 0;
	Q[save ++] = joe;
	while ( move < save ) {
		point New,now = Q[move ++];
		if ( !now.f ){
		if ( now.x == 0 || now.x == n-1 || now.y == 0 || now.y == m-1 ) {//到达边界
			printf("%d\n",now.s+1);
			return;
		}
		}
		for ( int i = 0 ; i < 4 ; ++ i ) {
			New.x = now.x + d[i][0];
			New.y = now.y + d[i][1];
			New.s = now.s + 1;
			New.f = now.f;
			if ( New.x >= 0 && New.x < n && New.y >= 0 && New.y < m )
			if ( maps[New.x][New.y] == '.' )//这样不仅#，F也不会过
				if ( New.f ) {
					maps[New.x][New.y] = 'F';
					Q[save ++] = New;
				}
				else if ( step[New.x][New.y]==inf ) {
					step[New.x][New.y] = step[now.x][now.y] + 1;
					Q[save ++] = New;
				}
		}
	}
	printf("IMPOSSIBLE\n");
}

int main()
{
	int c,n,m;
	while ( scanf("%d",&c) != EOF )
	while ( c -- ) {
		scanf("%d%d",&n,&m);
		for ( int i = 0 ; i < n ; ++ i )
			scanf("%s",maps[i]);
		bfs( n, m );
	}
	return 0;
}
