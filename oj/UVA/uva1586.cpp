#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int main()
{
    int t;
    double sum;
    double m[4]={12.01,1.008,16.00,14.01};
    int num[4];
    char a[85];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int length=strlen(a);
        memset(num,0,sizeof(num));
        for(int i=0;i<length;i++)
        {
            if(a[i]=='C')
            {

                if(isdigit(a[i+1])&&isdigit(a[i+2]))
                    num[0]+=10*(a[i+1]-'0')+(a[i+2]-'0');
                else
                    num[0]+=isdigit(a[i+1])?a[i+1]-'0':1;
            }

            else if(a[i]=='H')
            {
                if(isdigit(a[i+1])&&isdigit(a[i+2]))
                    num[1]+=10*(a[i+1]-'0')+(a[i+2]-'0');
                else
                    num[1]+=isdigit(a[i+1])?a[i+1]-'0':1;
            }
            else if(a[i]=='O')
            {
                if(isdigit(a[i+1])&&isdigit(a[i+2]))
                    num[2]+=10*(a[i+1]-'0')+(a[i+2]-'0');
                else
                    num[2]+=isdigit(a[i+1])?a[i+1]-'0':1;
            }
            else if(a[i]=='N')
            {
                if(isdigit(a[i+1])&&isdigit(a[i+2]))
                    num[3]+=10*(a[i+1]-'0')+(a[i+2]-'0');
                else
                    num[3]+=isdigit(a[i+1])?a[i+1]-'0':1;
            }
        }
        sum=0;
        for(int i=0;i<4;i++)
        {
            sum+=(num[i]*m[i]);
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
