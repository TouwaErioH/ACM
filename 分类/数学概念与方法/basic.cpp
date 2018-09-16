

bool is_prime(int n) {
  int m = floor(sqrt(n) + 0.5);
  for(int a = 2; a <= m; a++)        //比a*a《=要好，少做乘法
    if(n % a == 0) return false;
  return true;
}



    1.欧几里得算法

求解最大公约数，时间复杂度在O(log max(a,b))  //x和0的最大公约数是x
    int gcd(int a,int b)                     //两个自然数的乘积等于这两个自然数的最大公约数和最小公倍数的乘积
    {
        return (b==0)?a:gcd(b,a%b);          //求lcm  a/gcd（a，b）*b   顺序不要错，会溢出
    }


    2.扩展欧几里得算法

求解方程a*x+b*y=gcd(a,b)，a、b、x、y均为整数，时间复杂度和辗转相除法是相同的，函数返回gcd(a,b)
//解一定存在，根据数论中的相关定理
    int gcd(int a,int b)                    // |     |x|<=a |y|<=b;
    {
        return (b==0)?a:gcd(b,a%b);
    }
    int extgcd(int a,int b,int& x,int& y)   //d=gcd(a,b)
    {
        int d=a;
        if(b!=0){
            d=extgcd(b,a%b,y,x);
            y-=(a/b)*x;
        }
        else{
            x=1;
            y=0;
        }
        return d;
    }

    void gcd(int a,int b,int& d,int &x,int &y){
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}


对任意ax+by=c的一组解x，y有如下：   c为gcd（a，b）的整数倍时有整数解；一组解是x0c/g，y0c/g

 x0+kb',y0-ka'   a'=a/gcd(a,b),b'=b/gcd(a,b)



    2.埃式筛法

给定一个正整数n，请问n以内有多少个素数。

首先将2到n的所有整数记下来，其中最小的整数2是素数，将表中2的倍数划去。表中最小的整数是3，它不能被更小的数整除，所以是素数，将表中3的倍数划去，以此类推，表中剩余的最小数字是m，则m就是素数。这样反复操作即可枚举得到n以内的所有素数，时间复杂度为O(nloglogn)，可以看作是线性时间。

int prime[maxn];
bool is_prime[maxn];//is_prime[i]是true表示i是素数
//返回n以内素数的个数
int sieve(int n)
{
int  m=sqrt(n+0.5);
memset(vis,0,sizeof(vis));
for(int i=2;i<=m;i++)
if(!vis[i])
for(int j=i*i;j<=n;j+=i)
vis[j]=1;
}

3.区间筛法

给定整数a、b，求区间[a,b)内有多少个素数

b以内的合数的最小质因数一定不超过√b。如果有√b以内的素数表，就可以把埃式筛法用到区间[a,b)上了。也就是说，先做好[2,√b)和[a,b)的表，然后从[2,√b)表中筛选素数的同时，也将其倍数从[a,b)的表中划去，最后剩下的就是[a,b)内的素数了。

typedef long long ll;
bool is_prime[1000000+5];
bool is_prime_small[1000000+5];
//对区间[a,b)内的整数执行筛法。is_prime[i-a]=true→i是素数
void segment_sieve(ll a,ll b)
{
    for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=true;
    for(int i=0;i<b-a;i++) is_prime[i]=true;
    for(int i=2;(ll)i*i<b;i++){
        if(is_prime_small[i]){
            for(int j=2*i;(ll)j*j<b;j+=i) is_prime_small[i]=false;//筛[2,√b)
            for(ll j=max(2ll,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;//筛[a,b)
            //2LL是2的长整数形式
            //((a+i-1)/i)*i是满足>=a&&%i==0的离a最近的数
            //也可以写成(a%i==0)?a:(a/i+1)*i
        }
    }
}

4.快速幂运算           //   同余式：正整数a，b对p取模，它们的余数相同，记做 或者a ≡ b (mod p)

typedef long long ll;
ll mod_pow(ll x,ll n,ll mod)   //   x^n mod (mod)   可以 mod 1
{                               //O（log（n））    //(a×b) mod c=(a mod c * b mod c) mod c
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int pow_mod(ULL a, ULL b, int n) {
  if(!b) return 1;
  int k = pow_mod(a, b/2, n);
  k = k * k % n;
  if(b % 2) k = k * a % n;
  return k;
}


euler筛法//还需要再研究，求个数先用埃式
明确：任何一个合数都是由一个素数序列相乘
利用每个合数必有一个最小素因子，每个合数仅被它的最小素因子筛去正好一次。所以为线性时间。

bool IsPrime[1000010];  //保证不做素数的倍数
int Prim[1000010];   //存素数
int  euler_prime(int n){
    int num = 0, j;
    for(int i = 2; i <= n; i ++){
        if(!IsPrime[i])   //不是目前找到的素数的倍数    1不是素数
            Prim[num ++] = i;  //记录质数
        for(j  = 0; j < num; j ++){
            if(i * Prim[j] > n)
                break;
            IsPrime[i * Prim[j]] = true;  //筛;//找到的素数的倍数不访问
            if(i % Prim[j] == 0)
                break;  //i可以看做prime[j]*某个数， i*prime[j+1]就可以看做 prime[j]*某个数*prime[j+1] 。而 prime[j] 必定小于 prime[j+1]，所以 i*prime[j+1] 必定已经被 prime[j]*某个数 筛掉，就不用再做了（等到i=6即最大合因子时会筛掉）
        }
    }
}
        if(i % prime[j] == 0) break;←_←这一步比较难理解
解释：
      首先，任何合数都能表示成多个素数的积。所以，任何的合数肯定有一个最小质因子。我们通过这个最小质因子就可以判断什么时候不用继续筛下去了。

      当i是prime[j]的整数倍时（i % prime[j] == 0），i*prime[j+1]肯定被筛过，跳出循环。

      因为i可以看做prime[j]*某个数， i*prime[j+1]就可以看做 prime[j]*某个数*prime[j+1] 。而 prime[j] 必定小于 prime[j+1]，
所以 i*prime[j+1] 必定将来 会被 prime[j]*某个数筛掉，就不用再做了√

      同时我们可以发现在满足程序里的两个条件的时候，prime[j]必定是prime[j]*i的最小质因子。这个性质在某些题里可以用到。

      这样就可以在线性时间内找到素数啦~\(≧▽≦)/~
