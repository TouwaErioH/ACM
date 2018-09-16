#include <bits/stdc++.h>
using namespace std;//感觉没什么技巧。。先特例，再乱序

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n],temp[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        temp[i]=a[i];
    }
    sort(temp,temp+n);
    int i=0;
    for(i;;i++)
    {
        if(a[i]==temp[0])
            break;
    }
        b[i]=temp[n-1];

    for(int i=1;i<n;i++)
        for(int j=0;;j++)
        if(a[j]==temp[i])
    {b[j]=temp[i-1];
    break;
    }
     for(int i=0;i<n;i++)
    printf("%d%c",b[i],i==n?'\n':' ');
    return 0;
}
