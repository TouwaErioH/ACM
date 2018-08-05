#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005
using namespace std;

int dp[105][N];  ///dp[k][i] ������ǰk���л���iȡ�õ�����ֵ
int a[105],price[105],value[105];
int main()
{
    int n,m,K;
    while(scanf("%d%d%d",&n,&m,&K)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&a[i],&price[i],&value[i]);
        }
        memset(dp,-1,sizeof(dp)); ///-1��ʾ״̬���Ϸ�
        for(int i=0; i<=m; i++) dp[0][i]=0;
        for(int k=1; k<=K; k++)
        {
            for(int i=1; i<=n; i++)
            {
                if(a[i]==k)                            //�ӵ�һ�ֿ�ʼ��������
                    for(int v=m; v>=price[i]; v--)
                    {
                        if(dp[k][v-price[i]] != -1)
                            dp[k][v] = max(dp[k][v] , dp[k][v - price[i]] + value[i]);
                        if(dp[k-1][v-price[i]] != -1 )
                            dp[k][v] = max(dp[k][v] , dp[k-1][v-price[i]] + value[i]);
                    }
            }
        }
        if(dp[K][m]==-1) printf("Impossible\n");
        else printf("%d\n",dp[K][m]);
    }
    return 0;
}

/*
�������һ��ʼ��dp��ʼ��Ϊ0��
������Ь�ӵļ�ֵ����0ʱ��
���Ǿ��޷���������ȫ�Ǽ���Ь�ӻ�������ȫ����
���ֵ��0
����01����.���ǵ�ǰѡ��k���ʱ��������ѡ����Ʒ��ʱ����ѡ�ĵڼ���.������ǵ�ǰ��ѡ��k���еĵ�һ����
��ô�Ǵӵ�k-1���ƹ�����,
�������ȡ��һ��(i)����ô���ǵ�k���е�ǰһ��(i-1)�ƹ�����.
���������и��ǳ���Ҫ�����⣬����д��Ҫд��������ʽ����if���ܵ�ת:
if(dp[k][v-price[i]] != -1)
        dp[k][v] = max(dp[k][v] , dp[k][v - price[i]] + value[i]);
if(dp[k-1][v-price[i]] != -1 )
        dp[k][v] = max(dp[k][v] , dp[k-1][v-price[i]] + value[i]);
���ͣ�˳���ܵ�ת����Ϊ�������Ϊ0����ת�Ļ����п��ܳ�������dp[k][v] = dp[k-1][v-0]+v������dp[k][v] =dp[k][v-0]+v = dp[k-1][v-0]+v+v,������Ʒȡ������.
*/
