#include<string.h>
#include<stdio.h>
using namespace std;
const int MAXN = 10000;

struct Command        //用cmd数组保存所有操作。
{
	char c[5];   //具体操作
	int r1, c1, r2, c2;  //交换的格
	int a, x[20];//操作次数与操作行列
}cmd[MAXN];
int r, c, n;  //n操作次数

int simulate(int* r0, int* c0)         //对所查询单元格模拟操作，返回操作后的位置（如果单元格被删去返回0）
{
	for (int i = 0; i < n; i++)
	{
		if (cmd[i].c[0] == 'E')
		{
			if (cmd[i].r1 == *r0 && cmd[i].c1 == *c0) { *r0 = cmd[i].r2; *c0 = cmd[i].c2; }
			else if (cmd[i].r2 == *r0 && cmd[i].c2 == *c0) { *r0 = cmd[i].r1; *c0 = cmd[i].c1; }//if因为查询的必然是两个格之一
		}
		else
		{
			int dr = 0, dc = 0;             //dr,dc记录行或列的增减
			for (int j = 0; j < cmd[i].a; j++)
			{
				int x = cmd[i].x[j];
				if (cmd[i].c[0] == 'I')
				{
					if (cmd[i].c[1] == 'R' && x <= *r0) dr++;
					if (cmd[i].c[1] == 'C' && x <= *c0) dc++;
				}
				else
				{
					if (cmd[i].c[1] == 'R' && x == *r0) return 0;
					if (cmd[i].c[1] == 'C' && x == *c0) return 0;
					if (cmd[i].c[1] == 'R' && x < *r0) dr--;
					if (cmd[i].c[1] == 'C' && x < *c0) dc--;
				}
			}
			*r0 += dr; *c0 += dc;           //更新单元格的新位置
		}
	}
	return 1;
}

int main()
{
	int r0, c0, q, kase = 0;
	while(scanf("%d%d%d",&r,&c,&n)==3&&r)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s",cmd[i].c);
			if (cmd[i].c[0] == 'E') scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			else {
				scanf("%d",&cmd[i].a);
				for (int j = 0; j < cmd[i].a; j++)
					scanf("%d",&cmd[i].x[j]);
			}
		}

		if (kase > 0) printf("\n");
		printf("Spreadsheet #%d\n",++kase);

		scanf("%d", &q);
		while (q--)
		{
			scanf("%d%d", &r0, &c0);
			printf("Cell data in (%d,%d) ", r0, c0);
			if (!simulate(&r0, &c0)) printf("GONE\n");
			else printf("moved to (%d,%d)\n", r0, c0);
		}
	}
	return 0;
}
