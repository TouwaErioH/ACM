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
        if(l%2==0)           //l分奇偶
        {
            a=l*l/2;
            b=2;
            c=l/2-1<<2;   //l长，a个不临，1个角
            ans=cal();
        }
        else
        {
            a=l*l/2;
            b=l==1 ? 1:4;
            c=l==0 ? 0:(l-l/2-2)*4;
            ans=cal();
            a=l*l/2+1;              //奇数时有从角开始和不从角开始两种方法
            b=0;
            c=(l-1)/2*4;
            ans=max(ans,cal());
        }
        cout<<ans<<endl;
    }
}


/*
贪心

将格子分为4类

1、隔一个选一个，互不相邻的格子

2、4个角上的格子   //-2+2=0

3、边界除角的格子     //-3+1=-2     //先互不相邻放，再放角，再边，再内部

4、内部的格子    //-4



4类从上到下依次选

1对答案有4的贡献

2对答案无贡献

3对答案有-2的贡献

4对答案有-4的贡献



对n奇偶分类讨论

当n为奇数时，在分左上角的格子在第1类还是第2类讨论
*/
