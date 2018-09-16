#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long LL;

#define N 12000
#define R 0.57721566490153286060651209

double a[N];

int main()
{
    int T,k,i,x;
    double sum=0.0;

    a[1]=1;
    for(i=2;i<=10000;i++)
        a[i]=a[i-1]+1.0/i;

    scanf("%d", &T);

    k=1;
    while(T--)
    {
        printf("Case %d: ", k++);
        scanf("%d", &x);
        if(x<=10000)
            printf("%.10f\n", a[x]);
        else
        {
            sum=log(x+1)+R-1.0/(2*x);
            printf("%.10f\n", sum);
        }
    }
    return 0;
}
