

bool is_prime(int n) {
  int m = floor(sqrt(n) + 0.5);
  for(int a = 2; a <= m; a++)        //��a*a��=Ҫ�ã������˷�
    if(n % a == 0) return false;
  return true;
}



    1.ŷ������㷨

������Լ����ʱ�临�Ӷ���O(log max(a,b))  //x��0�����Լ����x
    int gcd(int a,int b)                     //������Ȼ���ĳ˻�������������Ȼ�������Լ������С�������ĳ˻�
    {
        return (b==0)?a:gcd(b,a%b);          //��lcm  a/gcd��a��b��*b   ˳��Ҫ�������
    }


    2.��չŷ������㷨

��ⷽ��a*x+b*y=gcd(a,b)��a��b��x��y��Ϊ������ʱ�临�ӶȺ�շת���������ͬ�ģ���������gcd(a,b)
//��һ�����ڣ����������е���ض���
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


������ax+by=c��һ���x��y�����£�   cΪgcd��a��b����������ʱ�������⣻һ�����x0c/g��y0c/g

 x0+kb',y0-ka'   a'=a/gcd(a,b),b'=b/gcd(a,b)



    2.��ʽɸ��

����һ��������n������n�����ж��ٸ�������

���Ƚ�2��n������������������������С������2��������������2�ı�����ȥ��������С��������3�������ܱ���С����������������������������3�ı�����ȥ���Դ����ƣ�����ʣ�����С������m����m��������������������������ö�ٵõ�n���ڵ�����������ʱ�临�Ӷ�ΪO(nloglogn)�����Կ���������ʱ�䡣

int prime[maxn];
bool is_prime[maxn];//is_prime[i]��true��ʾi������
//����n���������ĸ���
int sieve(int n)
{
int  m=sqrt(n+0.5);
memset(vis,0,sizeof(vis));
for(int i=2;i<=m;i++)
if(!vis[i])
for(int j=i*i;j<=n;j+=i)
vis[j]=1;
}

3.����ɸ��

��������a��b��������[a,b)���ж��ٸ�����

b���ڵĺ�������С������һ����������b������С�b���ڵ��������Ϳ��԰Ѱ�ʽɸ���õ�����[a,b)���ˡ�Ҳ����˵��������[2,��b)��[a,b)�ı�Ȼ���[2,��b)����ɸѡ������ͬʱ��Ҳ���䱶����[a,b)�ı��л�ȥ�����ʣ�µľ���[a,b)�ڵ������ˡ�

typedef long long ll;
bool is_prime[1000000+5];
bool is_prime_small[1000000+5];
//������[a,b)�ڵ�����ִ��ɸ����is_prime[i-a]=true��i������
void segment_sieve(ll a,ll b)
{
    for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=true;
    for(int i=0;i<b-a;i++) is_prime[i]=true;
    for(int i=2;(ll)i*i<b;i++){
        if(is_prime_small[i]){
            for(int j=2*i;(ll)j*j<b;j+=i) is_prime_small[i]=false;//ɸ[2,��b)
            for(ll j=max(2ll,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;//ɸ[a,b)
            //2LL��2�ĳ�������ʽ
            //((a+i-1)/i)*i������>=a&&%i==0����a�������
            //Ҳ����д��(a%i==0)?a:(a/i+1)*i
        }
    }
}

4.����������           //   ͬ��ʽ��������a��b��pȡģ�����ǵ�������ͬ������ ����a �� b (mod p)

typedef long long ll;
ll mod_pow(ll x,ll n,ll mod)   //   x^n mod (mod)   ���� mod 1
{                               //O��log��n����    //(a��b) mod c=(a mod c * b mod c) mod c
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


eulerɸ��//����Ҫ���о�����������ð�ʽ
��ȷ���κ�һ������������һ�������������
����ÿ����������һ����С�����ӣ�ÿ����������������С������ɸȥ����һ�Ρ�����Ϊ����ʱ�䡣

bool IsPrime[1000010];  //��֤���������ı���
int Prim[1000010];   //������
int  euler_prime(int n){
    int num = 0, j;
    for(int i = 2; i <= n; i ++){
        if(!IsPrime[i])   //����Ŀǰ�ҵ��������ı���    1��������
            Prim[num ++] = i;  //��¼����
        for(j  = 0; j < num; j ++){
            if(i * Prim[j] > n)
                break;
            IsPrime[i * Prim[j]] = true;  //ɸ;//�ҵ��������ı���������
            if(i % Prim[j] == 0)
                break;  //i���Կ���prime[j]*ĳ������ i*prime[j+1]�Ϳ��Կ��� prime[j]*ĳ����*prime[j+1] ���� prime[j] �ض�С�� prime[j+1]������ i*prime[j+1] �ض��Ѿ��� prime[j]*ĳ���� ɸ�����Ͳ��������ˣ��ȵ�i=6����������ʱ��ɸ����
        }
    }
}
        if(i % prime[j] == 0) break;��_����һ���Ƚ������
���ͣ�
      ���ȣ��κκ������ܱ�ʾ�ɶ�������Ļ������ԣ��κεĺ����϶���һ����С�����ӡ�����ͨ�������С�����ӾͿ����ж�ʲôʱ���ü���ɸ��ȥ�ˡ�

      ��i��prime[j]��������ʱ��i % prime[j] == 0����i*prime[j+1]�϶���ɸ��������ѭ����

      ��Ϊi���Կ���prime[j]*ĳ������ i*prime[j+1]�Ϳ��Կ��� prime[j]*ĳ����*prime[j+1] ���� prime[j] �ض�С�� prime[j+1]��
���� i*prime[j+1] �ض����� �ᱻ prime[j]*ĳ����ɸ�����Ͳ��������ˡ�

      ͬʱ���ǿ��Է�������������������������ʱ��prime[j]�ض���prime[j]*i����С�����ӡ����������ĳЩ��������õ���

      �����Ϳ���������ʱ�����ҵ�������~\(�R���Q)/~
