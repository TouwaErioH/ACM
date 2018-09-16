#include<iostream>
using namespace std;
const int maxn=1000010;
int ans[maxn];
bool IsPrime[maxn];
int Prim[maxn];

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

int digitsum(int val)
{
    int result = 0;

    while(val) {
        result += val % 10;
        val /= 10;
    }
    return result;
}

void setans()
{
    int sum = 1, i;

    for(i=3; i<=maxn; i+=2) {
        if(!IsPrime[i] && !IsPrime[digitsum(i)])
            sum++;
        ans[i] = sum;
        ans[i+1] = sum;
    }
}

int main()
{
    int t, l, r, i;

    euler_prime(maxn);
    ans[2]=1;
    setans();

    scanf("%d", &t);
    for(i=1; i<=t; i++) {
        scanf("%d%d", &l, &r);
        printf("Case #%d: %d\n", i, ans[r] - ans[l-1]);
    }
    return 0;
}
