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

int pow(int a,int n)//����ֵ��a��n�η�
{
    int result=1,flag=a;
    while(n!=0)
    {
        if(n&1)//���n����������n�Ķ�������ĩλΪ1ʱ
            result=result*flag;
        flag=flag*flag;
        n=n>>1;//n�Ķ���������һλ����n/2
    }
    return result;
}


int pow(int a,int n,int b)//����ֵ��a��n�η���bȡ����ֵ  ԭ������ȡ�����ȡ��Ļ�ȡ��
{
    int result=1;
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



