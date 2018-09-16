#include <iostream>
#include <cstdio>
const int MAX_ML = 1e4 + 10;
const int MAX_MD = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1010;
int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];
int d[MAX_N];
bool updated;
using namespace std;

void update(int &x,int y)
{
    if(x>y){
        x=y;
    updated=true;
    }
}

void bellmanford()
{
    // 用Bellman-Ford算法计算d
	for (int k = 0; k <=N; k++)
	{
		updated=false;
		for (int i = 0; i + 1 < N; i++){
		if (d[i + 1] < INF) update(d[i],d[i+1]);
		}

		// 从 AL 到 BL 的权值为 DL
		for (int i = 0; i < ML; i++)
		{
			if (d[AL[i] - 1] < INF)
			update( d[BL[i] - 1], d[AL[i] - 1] + DL[i] );
		}

		// 从 BD 到 AD 的权值为 -DD
		for (int i = 0; i < MD; i++)
		{
			if (d[BD[i] - 1] < INF)
			update( d[AD[i] - 1], d[BD[i] - 1] - DD[i] );

		}
	}
}

void solve()
{
	fill(d,d+N,0);
	bellmanford();
	if(updated){
        printf("-1\n");
        return;
	}

	fill(d, d + N, INF);
	d[0] = 0;
	bellmanford();
	int res = d[N - 1];
	if (res == INF)
	res=-2;
	printf("%d\n",res);
}

int main()
{
	scanf("%d%d%d",&N,&ML,&MD);
	for (int i = 0; i < ML; i++)
    scanf("%d%d%d",&AL[i],&BL[i],&DL[i]);
    for (int i = 0; i < MD; i++)
        scanf("%d%d%d",&AD[i],&BD[i],&DD[i]);
	solve();
	return 0;
}
