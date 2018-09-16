#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s1[105],s2[105];
int a[28],b[28];

    int main()
    {

        while(~scanf("%s%s",s1,s2))
        {
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            int len1 = strlen(s1);
            int len2 = strlen(s2);
            for(int i = 0; i < len1; i++)
                a[s1[i]-'A']++;
            for(int i = 0; i < len2; i++)
                b[s2[i]-'A']++;
            sort(a,a+26);
            sort(b,b+26);
            int flag = 1;
            for(int i = 0; i < 26; ++i)
            {
                if(a[i] != b[i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
        return 0;
    }
