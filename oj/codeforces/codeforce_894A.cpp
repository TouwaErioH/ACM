#include<bits/stdc++.h>
int main()
{
    char a[105];
    int n,Q=0,q=0,sum=0;
    scanf("%s",a);
    n=strlen(a);
    for(int i=0;i<n;i++)
    {
        if(a[i]=='Q')
        Q++;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]=='Q')
            q++;
        if(a[i]=='A')
            sum+=(q*(Q-q));
    }
    printf("%d",sum);

    return 0;
}
