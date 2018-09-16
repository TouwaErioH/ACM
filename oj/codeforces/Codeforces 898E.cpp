#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N],b[N],c[N];
  int main()
{
    int n=0;int po=0;int pp=0;
    /*int b[200005]={0};
    int a[200005]={0};
    int c[200005]={0};*/ //why?
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int sq=sqrt(a[i]);
        if(sq*sq==a[i])
        {if(a[i]==0)
            b[po]=2;
         else
            b[po]=1;
            po++;
        }
         else
        {
        c[pp]=min(a[i]-sq*sq,(sq+1)*(sq+1)-a[i]);
        pp++;
        }
    }
    sort(b,b+po);
    sort(c,c+pp);


    if(po==(n/2))
        printf("0\n");
    else if(po<pp)
    {
        int k=n/2-po;
        for(int j=0;j<k;j++)
        ans=ans+c[j];
        printf("%lld\n",ans);
    }
    else
    {
        int k=n/2-pp;
        for(int j=0;j<k;j++)
            ans=ans+b[j];
        printf("%lld\n",ans);
    }
        return 0;
}
