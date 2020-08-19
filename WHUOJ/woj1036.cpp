// dp   dp[i] = dp[i-1] + dp[i-2] +dp[i-3] 高精度
// 直接用java  BigInteger

//离线处理
/*
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner (System.in);
        BigInteger[] dp=new BigInteger[505];
        dp[1]=new BigInteger("1");
        dp[2]=new BigInteger("2");
        dp[3]=new BigInteger("4");
        for(int i=4;i<=500;i++)
            dp[i] = dp[i - 1].add(dp[i - 2].add(dp[i - 3]));
        int n;
        while(cin.hasNext())//等价于!=EOF
        {
            n = cin.nextInt();
            if(n == 0) break;
            System.out.println(dp[n]);
        }
        }
    }
*/
    //cpp
    /*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
 
string Sum(string a,string b)//这个就是高精加法,可以通用滴
{
    if(a.length()<b.length())
    {
        string temp=a; a=b; b=temp;
    }
    int i,j;
    for(i=a.length()-1,j=b.length()-1;i>=0;i--,j--)
    {
        a[i]=(a[i]+(j>=0?b[j]-'0':0));
        if(a[i]>'9')
        {
            a[i] -=10;
            if(i) a[i-1]++;
            else a='1'+a;
        }
    }
    return a;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string a[501];
    a[1]="1"; a[2]="2"; a[3]="4";
    //cout<<a[1]<<endl<<a[2]<<endl<<a[3]<<endl;
    int n,i;
    for(i=4;i<=500;i++)//这里需要注意,设置a[501],那么只能到500,不然运行时出错,不知道为什么,求解
    {
        a[i]=Sum(a[i-1],a[i-2]);
        a[i]=Sum(a[i],a[i-3]);
    }
    while(cin>>n && n)
      cout<<a[n]<<endl;
 
    return 0;
}
————————————————
版权声明：本文为CSDN博主「东心土木」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/czl1252409767/java/article/details/8863554

    */