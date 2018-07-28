#include<cstdio>
#include<cstring>
char field[110][110];
int d[8][2]={1,0,-1,0,0,1,0,-1,1,1,-1,-1,1,-1,-1,1};
int r,c;
void dfs(int x,int y)
{
    int next_x,next_y,i;
    field[x][y]='*';
    for(i=0;i<8;i++)
    {
        next_x=x+d[i][0];
        next_y=y+d[i][1];
        if(next_x>=0&&next_x<r&&next_y>=0&&next_y<c&&field[next_x][next_y]=='@')
        dfs(next_x,next_y);
    }
    return ;
}
int main()
{
    int i,j,sum;
    while(scanf("%d%d",&r,&c)&&r!=0)
    {
        for(i=0;i<r;i++)
        scanf("%s",field[i]);
        sum=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(field[i][j]=='@')
                {
                    dfs(i,j);
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
