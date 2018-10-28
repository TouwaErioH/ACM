int binarysearch(int x)
{
    int l=0,r=n*n;
    while(r-l>=1)
    {
        int i=(r+l)/2;
        if(num[i]==x) return 1;
        else if(num[i]<x) l=i+1;
        else r=i;
    }
    return 0;
}

    int gcd(int a,int b)
    {
       // return (b==0)?gcd(b,a%b):a
         if(b==0)
              return a;
         else
              return gcd(b,a%b);
    }

ll pow(ll a,ll n)//返回值是a的n次方
{
    ll result=1,flag=a;
    while(n!=0)
    {
        if(n&1)//如果n是奇数，即n的二进制最末位为1时
            result=result*flag;
        flag=flag*flag;
        n=n>>1;//n的二进制右移一位，即n/2
    }
    return result;
}


ll pow(ll a,ll n,ll b)//返回值是a的n次方对b取余后的值  原理：积的取余等于取余的积取余
{
    ll result=1;
    a=a%b;//积的取余等于取余的积取余
    while(n>0)
    {
        if(n%2==1)
            result=result*a%b;//n是奇数的话就要多乘一次，原理和前面的二分求幂一样
        n=n/2;//二分
        a=a*a%b;//积的取余等于取余的积取余
    }
    return result;
}

void eratosthenes_sieve(int n)
{
    totPrimes = 0;
    memset(flag, 0, sizeof(flag));

    int sqrtn = sqrt(n + 0.5);
    for (int i = 2; i <= sqrtn; i++) {
        if (!flag[i]) {
            primes[totPrimes++] = i;
            for (int j = i * i; j <= n; j += i) {
                flag[j] = true;
            }
        }
    }
    for (int i = sqrtn + 1; i <= n; i++) {
        if (!flag[i])
            primes[++totPrimes] = i;
    }
}

void euler_sieve(int n)
{
    totPrimes = 0;
    memset(flag, 0, sizeof(flag));

    for (int i = 2; i <= n; i++) {
        if (!flag[i])
            primes[totPrimes++] = i;
        for (int j = 0; i * primes[j] <= n; j++) {
            flag[i*primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

bool isPrime(int n) {

	if (n < 2)
		return false;
   int m=sqrt(n+0.5);
	for (int i = 2; i <= m; i++) {

		if (n % i == 0)
			return false;
	}

	return true;
}

