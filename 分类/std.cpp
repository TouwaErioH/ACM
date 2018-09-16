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

int pow(int a,int n)//返回值是a的n次方
{
    int result=1,flag=a;
    while(n!=0)
    {
        if(n&1)//如果n是奇数，即n的二进制最末位为1时
            result=result*flag;
        flag=flag*flag;
        n=n>>1;//n的二进制右移一位，即n/2
    }
    return result;
}


int pow(int a,int n,int b)//返回值是a的n次方对b取余后的值  原理：积的取余等于取余的积取余
{
    int result=1;
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



