#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1000;
char a[maxn];
struct BIGNUM{
    static const int base=10000;
    static const int baseL=4;
    int num[maxn],len;
    BIGNUM (){memset(num,0,sizeof(num));len=1;}
    BIGNUM operator = (int x)
    {
        memset(num,0,sizeof(num));
        int tmp=x;len=0;for(;tmp;tmp/=10)len++;
        a[len]='\0';tmp=x;
        for(int i=len-1;i>=0;i--) a[i]='0'+tmp%10,tmp/=10;
        return *this=a;
    }
    BIGNUM operator = (const char* s)
    {
        memset(num,0,sizeof(num));
        len=strlen(s);
        for(int cnt=0;baseL*cnt<=len;cnt++)
            for(int j=baseL;j>=1;j--)
                if(len-cnt*baseL-j>=0) num[cnt]=num[cnt]*10+s[len-cnt*baseL-j]-'0';
        len=len/baseL+(len%baseL!=0);
        return *this;
    }
    BIGNUM(const int rhs){*this=rhs;}
    BIGNUM operator *(const BIGNUM& x)
    {
        BIGNUM c;
        c.len=len+x.len;
        for(int i=0;i<x.len;i++)
            for(int j=0;j<len;j++)
            {
                c.num[i+j]+=num[j]*x.num[i];
                c.num[i+j+1]+=c.num[i+j]/base;
                c.num[i+j]%=base;
            }
        while(c.num[c.len-1]==0&&c.len>1)c.len--;
        return c;
    }
    BIGNUM operator *=(const BIGNUM& rhs){return *this=*this * rhs;}
    BIGNUM operator + (const BIGNUM& rhs)const{
        BIGNUM c;
        int alen;
        alen=max(rhs.len,len);
        c.len=alen+1;
        int x=0;
        for(int i=0;i<=alen;i++)
        {
            if(i<rhs.len){x+=rhs.num[i];}
            if(i<len){x+=num[i];}
            c.num[i]+=x%base;
            x/=base;
        }
        while(c.num[c.len-1]==0&&c.len>1)c.len--;
        return c;
    }
    BIGNUM operator += (const BIGNUM& rhs){return *this=*this+rhs;}
    BIGNUM operator - (const BIGNUM& rhs)const{
        BIGNUM c;c.len=len;
        for(int i=0;i<len;i++)
        {
            c.num[i]=c.num[i]+num[i]-rhs.num[i];
            if(c.num[i]<0) c.num[i]+=base,c.num[i+1]-=1;
        }
        while(c.num[c.len-1]==0&&c.len>1) c.len--;
        return c;
    }
    BIGNUM operator -= (const BIGNUM& rhs){return *this=*this-rhs;}
    BIGNUM operator / (const int &rhs)const{//高精除低精做法
        BIGNUM c;c.len=len;
        long long x=0;
        for(int i=len-1;i>=0;--i)
        {
            x=x*base+num[i];
            c.num[i]=x/rhs;
            x%=rhs;
        }
        while(c.num[c.len-1]==0&&c.len>1) --c.len;
        return c;
    }
};
istream&  operator >> (istream& in,BIGNUM &x){
    in>>a;x=a;return in;
}
ostream&  operator << (ostream& out,const BIGNUM &x)
{
    printf("%d",x.num[x.len-1]);
    for(int i=x.len-2;i>=0;i--)
      printf("%04d",x.num[i]);
    return out;
}

typedef BIGNUM ll;

inline void solve()
{
    ll n;cin>>n;
    n=n*n*n*n+(ll)23*n*n-(ll)6*n*n*n-(ll)18*n;
    cout<<n/24+(ll)1<<endl;
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
    return 0;
}
