#include <stdio.h>

int main()
{
    int c,p=1;
    while((c=getchar())!=EOF)
    {
        if(c=='"')
        {
            printf("%s",p?"``":"''");
            p=!p;
        }
        else
            printf("%c",c);
    }
    return 0;
}
