#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int r[10][10],c[10][10],n,m;

int main()
{
    int flag=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        getchar();
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        char d;int x,y;
        for (int i = 1 ; i <= m ; ++ i) {
        scanf("%c%d%d",&d,&x,&y);
        getchar();
			if (d == 'H')
				r[x][y] = 1;
			else
				c[y][x] = 1;
		}
        if (flag) printf("\n**********************************\n\n");
        flag++;
        printf("Problem #%d\n\n",flag);
        int sum=0;
        for(int len=1;len<=n;len++){
                int cnt=0;
        for(int i=1;i<=n-len;i++)
            for(int j=1;j<=n-len;j++){
                       int sqr = 1;
				for (int j1 = j ; j1 < j+len ; j1++)
					if (!r[i][j1] || !r[i+len][j1]) sqr = 0;
				for (int i1 = i ; i1 < i+len ; i1++)
					if (!c[i1][j] || !c[i1][j+len]) sqr = 0;
			if(sqr) cnt++;
            }
            sum=sum+cnt;
            if (cnt) printf("%d square (s) of size %d\n",cnt,len);
        }
        if (!sum) printf("No completed squares can be found.\n");
    }
    system("pause");
    return 0;
}
