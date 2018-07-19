    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    int main()
    {
    	char s[11][11];//储存字符
    	int r, c, i, j, k, a[11][11], d[11][11], first=1, countl=0;//a获得起始格，b储存序号
    	while (~scanf("%d",&r)&&r)
    	{
    		scanf("%d", &c);
    		for (i = 1;i <= r;i++)
    			scanf("%s", s[i]+1);//空出第一列，与a，b对应
    		memset(a, 0, sizeof(a));
    		memset(d, 0, sizeof(d));
    		k = 0;
    		for (i = 1;i <= r;i++)
    			for (j = 1;j <= c;j++)
    			{
    				if (s[i][j]!='*') a[i][j] = 1;//a[i][j]=1表示白格
    				if (a[i][j]&&(a[i][j-1]==0||a[i-1][j]==0)) d[i][j] = ++k;//d[i][j]=k表示该起始格的编号是k，多用一行一列表示边界
    			}
    		if (first) first = 0;
    		else putchar('\n');
    		printf("puzzle #%d:\nAcross\n", ++countl);
    		for (i = 1;i <= r;i++)
    			for (j = 1;j <= c;j++)
    			{
    				if (d[i][j] && a[i][j-1] ==0)//进一步对起始格做规范
    				{
    					printf("%3d.", d[i][j]);//样例输出是3单位右对齐！
    					for (k = j;a[i][k] == 1 && k <= c;k++)
    						putchar(s[i][k]);
    					putchar('\n');
    				}
    			}
    		printf("Down\n");
    		for (i = 1;i <= r;i++)
    			for (j = 1;j <= c;j++)
    			{
    				if (d[i][j]&&a[i-1][j]==0)
    				{
    					printf("%3d.", d[i][j]);
    					for (k = i;a[k][j] == 1 && k <= r;k++)
    						putchar(s[k][j]);
    					putchar('\n');
    				}
    			}
    	}
    	return 0;
    }
