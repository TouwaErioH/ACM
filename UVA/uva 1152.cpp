#include <cstdio>
#include <algorithm>
using namespace std;
int k[4005][4],sum[4005*4005];int cas,n;

int bsearch(int x)
{
    int l=0,r=n*n;
    while(r-l>=1)
    {
        int i=(r+l)/2;
        if(sum[i]==x)
        {
            int ans=1;
            int g=i;
        while((sum[g+1]==x)&&i!=n-1)//这个&&也很重要
            {
            g++;
            ans++;}
            while((sum[i-1]==x&&i!=0))
            {
                i--;
                ans++;
            }
            return ans;}
        else if(sum[i]<x)
        l=i+1;
        else
        r=i;
    }
    return 0;
}
int main()
{
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {for(int j=0;j<4;j++)
            scanf("%d",&k[i][j]);}
        int ans=0;
        for(int a=0;a<n;a++)
            {for(int b=0;b<n;b++)
                sum[a*n+b]=k[a][0]+k[b][1];}
            sort(sum,sum+n*n);
        for(int c=0;c<n;c++)
           {
            for(int d=0;d<n;d++)
            {
            int h=0;
            if((h=bsearch(-k[c][2]-k[d][3]))!=0)//问题在于不是存在而是所有，不能简单的二分法
            ans=ans+h;}
           }
            printf("%d\n",ans);
            if(cas)
                printf("\n");
    }
    return 0;
}
