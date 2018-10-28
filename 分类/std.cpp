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

ll pow(ll a,ll n)//����ֵ��a��n�η�
{
    ll result=1,flag=a;
    while(n!=0)
    {
        if(n&1)//���n����������n�Ķ�������ĩλΪ1ʱ
            result=result*flag;
        flag=flag*flag;
        n=n>>1;//n�Ķ���������һλ����n/2
    }
    return result;
}


ll pow(ll a,ll n,ll b)//����ֵ��a��n�η���bȡ����ֵ  ԭ������ȡ�����ȡ��Ļ�ȡ��
{
    ll result=1;
    a=a%b;//����ȡ�����ȡ��Ļ�ȡ��
    while(n>0)
    {
        if(n%2==1)
            result=result*a%b;//n�������Ļ���Ҫ���һ�Σ�ԭ���ǰ��Ķ�������һ��
        n=n/2;//����
        a=a*a%b;//����ȡ�����ȡ��Ļ�ȡ��
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

