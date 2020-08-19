/*
    Name: 
    Copyright: 
    Author: LJS
    Date: 13/01/16 11:10
    Description: woj1058
    组合数学中经典的母函数问题,
    (1+x+x^2+...+x^n)*(1+x^2+x^4+...+(x^2)^(n/2))*(1+x^3+x^6+(x^3)^(n/3))
    模拟多项式的展开，求x^n的系数 
*/
#include<iostream>

using namespace std;
long long n,i,j,ans;

long long solve(long long n){
           ans=0;
    for(i=n/3;i>=0;--i)
        {
 
            j=(n- i * 3)/2 + 1;
            ans = ans + j;
        }
        return ans;
}

int main()
{
    while(cin>>n&&n)
        cout<<solve(n)<<endl;
    return 0;
}