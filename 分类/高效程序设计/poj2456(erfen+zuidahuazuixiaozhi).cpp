#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int x[100001],N,C;
bool solve(int d)
{
    int last=0;
    for(int i=1;i<C;i++)
     {
         int crt=last+1;
         while(crt<N&&x[crt]-x[last]<d){

            crt++;
         }
         if(crt==N)
            return false;
         last=crt;
     }
     return true;
}
int main()
{
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++)
        scanf("%d",&x[i]);
    sort(x,x+N);
    int low=0,rf=x[N-1]+5,mid;
    while(low+1<rf)
    {
        mid=(low+rf)/2;
        if(solve(mid))
            low=mid;
        else
            rf=mid;
    }
   printf("%d\n",rf-1);
}
