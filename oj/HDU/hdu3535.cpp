#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Ni = 120;
int dp[Ni][Ni];
int main()
{
    int n,m,i,j,k,num,c,v,typ;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&num,&typ);
            if(typ==0) for(int p=0;p<=m;p++) dp[i][p]=-1;//�����ѡ��Ϊ-1
            else for(int p=0;p<=m;p++) dp[i][p]=dp[i-1][p];//����һ������ֵ������ȥ
            for(j=1;j<=num;j++)
            {
                scanf("%d%d",&c,&v);
                for(k=m;k>=c;k--)
                {
                    if(typ==0)//����ѡһ��
                    {
                        if(dp[i][k-c]!=-1)//ǰ���б�ѡ��ûѡ��������ѡ
                        dp[i][k]=max(dp[i][k],dp[i][k-c]+v);

                        if(dp[i-1][k-c]!=-1)
                        dp[i][k]=max(dp[i][k],dp[i-1][k-c]+v);

                    }
                    else if(typ==1)//���ѡһ��
                    {
                        if(dp[i-1][k]!=-1)
                        dp[i][k]=max(dp[i][k],dp[i-1][k]); //��ѡ

                        if(dp[i-1][k-c]!=-1)
                        dp[i][k]=max(dp[i][k],dp[i-1][k-c]+v);  //ѡ

                    }
                    else //����
                    {
                        if(dp[i-1][k]!=-1)
                        dp[i][k]=max(dp[i][k],dp[i-1][k]);

                        if(dp[i][k-c]!=-1)
                        dp[i][k]=max(dp[i][k],dp[i][k-c]+v);

                        if(dp[i-1][k-c]!=-1)
                        dp[i][k]=max(dp[i][k],dp[i-1][k-c]+v);

                    }
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
