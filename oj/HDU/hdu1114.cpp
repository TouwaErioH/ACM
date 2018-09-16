#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[10005];

int main()
{
    int t;
    int wa,wb,w;
    int n,val[505],wei[505],i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&wa,&wb);
        w = wb-wa;//�����ȥС��������
        scanf("%d",&n);
        for(i = 0;i<n;i++)
        scanf("%d%d",&val[i],&wei[i]);
        for(i = 0;i<=w;i++)
        {
            dp[i] = 10000000;//��ΪҪ��С�ģ�����dp�����������
        }
        dp[0] = 0;
        for(i = 0;i<n;i++)
        {
            for(j = wei[i];j<=w;j++)
            {
                dp[j] = min(dp[j],dp[j-wei[i]]+val[i]);
            }
        }
        if(dp[w] == 10000000)
        printf("This is impossible.\n");
        else
        printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
    }

    return 0;
}
