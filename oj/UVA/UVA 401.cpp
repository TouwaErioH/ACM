    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>

  const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    const char* msg[]={"not a palindrome", "a regular palindrome","a mirrored string","a mirrored palindrome"};
    char r(char ch)
    {
        if(isalpha(ch))
return rev[ch-'A'];
       else
            return  rev[ch-'0'+25];
    }
    int main (void)
    {
        char a[40];
        while(scanf("%s",a)==1)
        {
            int n=1;
            int m=1;
            for(int i=0; i<(strlen(a)+1)/2; i++)
            {
                if(a[i]!=a[strlen(a)-i-1])
                {
                    m=0;
                }
                if(r(a[i])!=a[strlen(a)-1-i])
                {
                    n=0;
                }
            }
            printf("%s -- is %s.\n\n",a,msg[m+2*n]);
        }
        return 0;
    }
