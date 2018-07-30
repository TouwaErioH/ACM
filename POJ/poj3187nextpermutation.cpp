#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int a[15],b[15];
    int N,value;
    while(~scanf("%d %d",&N,&value))
    {
        for(int i=0;i<=N;i++)
                a[i]=b[i]=i;
        for(int i=2;i<=N;i++)
            for(int j=1;j<=N-i+1;j++)
                    b[j]=b[j]+b[j+1];
        if(b[1]==value)
        {
            for(int i=1;i<=N;i++)
                printf("%d ",a[i]);
            printf("\n");
        }
        else
        {
            while(next_permutation(a+1,a+N+1))
            {
                for(int i=0;i<=N;i++)
                    b[i]=a[i];
                for(int i=2;i<=N;i++)
                    for(int j=1;j<=N-i+1;j++)
                        b[j]=b[j]+b[j+1];
                    if(b[1]==value)
                {
                    for(int i=1;i<=N;i++)
                        printf("%d ",a[i]);
                    printf("\n");
                    break;
                }

            }
            }
        }
        return 0;
    }
