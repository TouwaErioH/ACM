#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[137];
    while(gets(s)!=NULL)
    {
        int i,sum,len;
        len=strlen(s);
        sum=0;
        for(i=0;i<len;i++)
        {
        if(s[i]=='!')
            printf("\n");
        else if(isdigit(s[i]))
          sum+=s[i]-'0';
        else
        {
            for(int j=sum;j>0;j--)
           {
                if(s[i]=='b')
                    printf(" ");
                else
                    printf("%c",s[i]);
            }
            sum=0;
        }
        }
            printf("\n");
        }
        return 0;
    }
