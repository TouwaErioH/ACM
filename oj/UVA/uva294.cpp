#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=40000;
bool IsPrime[maxn+5];
int Prim[maxn+5];

void  euler_prime(int n){
    int num = 0, j;
    for(int i = 2; i <= n; i ++){
        if(!IsPrime[i])
            Prim[num ++] = i;

        for(j  = 0; j < num; j ++){
            if(i * Prim[j] > n)
                break;
            IsPrime[i * Prim[j]] = true;
            if(i % Prim[j] == 0)
                break;
        }
    }

}

int cal(int n)
{
    int ans=1;

    for(int i=0;Prim[i]*Prim[i]<=n;i++)
    {
        if(n%Prim[i]==0)
        {
            int cnt=0;
            while(n%Prim[i]==0)
            {
                cnt++;
                n=n/Prim[i];
            }
            ans*=(cnt+1);
        }
    }
    if(n>1)
        ans*=2;
    return ans;
}

int main()
{
    euler_prime(maxn);
    int t,li,u;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&li,&u);
        int ans=0,id=0;

        for(int i=li;i<=u;i++)
        {
            int p=cal(i);

           if(p>ans)
           {
               ans=p;
               id=i;
           }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", li, u, id, ans);
    }
    return 0;
}
