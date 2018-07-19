#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int t,sum,cnt,i,len;
    char str[82];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        sum=0,cnt=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='O') cnt+=1;
            else cnt=0;
            sum+=cnt;
        }
        printf("%d\n",sum);
    }
    return 0;
}
