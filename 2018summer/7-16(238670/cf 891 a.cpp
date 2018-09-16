#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
int num[maxn];
int gcd(int a,int b);

int main()
{
    int n,ans=0;
    while(scanf("%d",&n)!=EOF)  //第一次没有判断
  {
    for(int i=0;i<n;i++)
    {
     scanf("%d",&num[i]);
     if (num[i]==1)   //==!!
            ans++;
    }
    int flag=0;
    if(ans!=0)
       {
        printf("%d",(n-ans));continue;
       }
    else
        {
            for(int i=0;i<n;i++){
                for(int j=0;j<n-i-1;j++)//gcd(gcd(a,b),c) = gcd(gcd(a,b),gcd(b,c))
            {
            num[j]=gcd(num[j],num[j+1]);  //相邻一开始没看到QAQ
            if(num[j]==1)
            {
            printf("%d\n",(i+n));
            flag=1;
            break;
            }
            }
            if (flag==1)
                break;
            }
        }
        if(flag==0)
            printf("-1\n");
    }
    return 0;
}

int gcd(int a,int b)
{
     if(b==0)
          return a;
     else
          return gcd(b,a%b);
}
