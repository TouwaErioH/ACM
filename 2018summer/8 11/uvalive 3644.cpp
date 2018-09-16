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
			x = find_par(x);   //˼·�������γɻ��򲻿ɣ���������һ���ߣ������㶼���������������γɻ����ɣ�
			y = find_par(y);   //���ƣ�һ��û���⣬2�֣�����û����3/4�֣�4�½�һ�����ϣ�3��������һ������Ԫ�ؾ��ڼ������򲻿ɣ���һ������Ϊ4��Ԫ�أ�֮���ظ��������
			if(x == y) ans++;
			else par[x] = y;
			scanf("%d", &x);
		}
		printf("%d\n", ans);
	}
	return 0;
}
