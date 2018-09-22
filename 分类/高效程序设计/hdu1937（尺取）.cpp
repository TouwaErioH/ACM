#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

int  sum[310][310];
int main()
{

    int r,c,k;
    while(scanf("%d%d%d",&r,&c,&k)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        if(r==0&&c==0&&k==0)
            break;
        int i,j;
        char ch;
        for(i=1;i<=r;i++)
        {
          for(j=1;j<=c;j++)
          {
            cin>>ch;
            int t;
            t=(ch=='.');
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;
          }
        }
        int ans=r*c;

        for(i=1;i<=r;i++)     //i,j�ֱ�Ϊ�е����޺�����
        for(j=i;j<=r;j++)
        {
           int l,rr;
           l=rr=1;       //��ȡ�ҷ����������е�����������
           while(1)
           {
           //�����ر�ע�����С�����ڡ�.���ĸ����ķ���
               while(sum[j][rr]-sum[j][l-1]-sum[i-1][rr]+sum[i-1][l-1]<k&&rr<=c)
                    rr++;
               if(sum[j][rr]-sum[j][l-1]-sum[i-1][rr]+sum[i-1][l-1]<k)
                   break;
               if(sum[j][rr]-sum[j][l-1]-sum[i-1][rr]+sum[i-1][l-1]>=k)
               {
                 ans=min(ans,(rr-l+1)*(j-i+1));
               }
               l++;
           }
        }
        cout<<ans<<endl;
    }
    return 0;
}
