#include<cstdio>
int a[10001][10];
int main()
{
    for(int i=1;i<10001;i++)    //打表+利用之前的值
    {
        for(int j=0;j<10;j++)
            a[i][j]=a[i-1][j];
        for(int k=i;k;k/=10)
            a[i][k%10]++;
    }
    int t;
    scanf("%d",&t);
    while(t)
    {
        int num;
        scanf("%d",&num);
        for(int j=0;j<9;j++)
            printf("%d ",a[num][j]);
        printf("%d\n",a[num][9]);
        t--;
    }
    return 0;
}
