#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll l,n,a,b,c,ans;
ll cal()
{
    if(n<=a) return n*4;
    if(n<=a+b) return a*4;
    if(n<=a+b+c) return a*4-(n-a-b)*2;
    return a*4-c*2-(n-a-b-c)*4;
}
int main()
{
    while(cin>>l>>n,l||n)
    {
        if(l%2==0)           //l����ż
        {
            a=l*l/2;
            b=2;
            c=l/2-1<<2;   //l����a�����٣�1����
            ans=cal();
        }
        else
        {
            a=l*l/2;
            b=l==1 ? 1:4;
            c=l==0 ? 0:(l-l/2-2)*4;
            ans=cal();
            a=l*l/2+1;              //����ʱ�дӽǿ�ʼ�Ͳ��ӽǿ�ʼ���ַ���
            b=0;
            c=(l-1)/2*4;
            ans=max(ans,cal());
        }
        cout<<ans<<endl;
    }
}


/*
̰��

�����ӷ�Ϊ4��

1����һ��ѡһ�����������ڵĸ���

2��4�����ϵĸ���   //-2+2=0

3���߽���ǵĸ���     //-3+1=-2     //�Ȼ������ڷţ��ٷŽǣ��ٱߣ����ڲ�

4���ڲ��ĸ���    //-4



4����ϵ�������ѡ

1�Դ���4�Ĺ���

2�Դ��޹���

3�Դ���-2�Ĺ���

4�Դ���-4�Ĺ���



��n��ż��������

��nΪ����ʱ���ڷ����Ͻǵĸ����ڵ�1�໹�ǵ�2������
*/
