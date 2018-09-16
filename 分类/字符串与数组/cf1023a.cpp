#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char a[200005];
char b[200005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
        scanf("%s",a);
        scanf("%s",b);
        char c[200006];
        if (n>(m+1))
        {
            printf("NO\n");
        }
        else
        {
            int f=-1;
            for (int i=0; i<n; i++)
            {
                if (a[i]=='*')
                {
                    f=i;
                    for (int j=i+1; j<n; j++)
                    {
                        c[j-i-1]=a[j];
                    }
                    c[n-i-1]='\0';
                    break;
                }
            }
            if (f==-1){
                if (!strcmp(a,b)){
                    printf("YES\n");
                    return 0;
                }
                else
                {
                    printf("NO\n");
                    return 0;
                }
            }
            int lenc=strlen(c);
            int flag=0;

            for(int i=0;i<f;i++){
              if (a[i]!=b[i]){
                flag=1;
                break;
              }
            }
            for (int i=m-1; i>=m-lenc; i--)
            {
                if( b[i]!=c[i-m+lenc]){
                    flag=1;
                    break;
                }
            }
        if (flag==0)printf("YES\n");
        else printf("NO\n");
    }
return 0;
}
