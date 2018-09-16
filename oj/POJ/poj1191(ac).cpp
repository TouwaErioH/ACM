/*感觉没什么区别*/
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int mp[9][9];
int sum[9][9];
int d[15][9][9][9][9];

int needsum(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}

int min(int a,int b)
{ return a>b?b:a; }

int fun(int k,int x1,int y1,int x2,int y2)
{
    int t,a,b,c,e,MIN=10000000;
    if(d[k][x1][y1][x2][y2] !=-1)
        return d[k][x1][y1][x2][y2];
    if(k==0)
    {
        t=needsum(x1,y1,x2,y2);
        d[k][x1][y1][x2][y2]=t*t;
        return t*t;
    }
    for(a=x1;a<x2;a++)
    {
        c=needsum(a+1,y1,x2,y2);
        e=needsum(x1,y1,a,y2);
        t=min(fun(k-1,x1,y1,a,y2)+c*c,fun(k-1,a+1,y1,x2,y2)+e*e);
        if(MIN>t) MIN=t;
    }
    for(b=y1;b<y2;b++)
    {
        c=needsum(x1,b+1,x2,y2);
        e=needsum(x1,y1,x2,b);
        t=min(fun(k-1,x1,y1,x2,b)+c*c,fun(k-1,x1,b+1,x2,y2)+e*e);
        if(MIN>t) MIN=t;
    }
    d[k][x1][y1][x2][y2]=MIN;
    return MIN;
}
int main()
{
    memset(sum ,0 ,sizeof(sum));
    memset(d ,-1 ,sizeof(d));
    int n;
    cin>>n;
    for (int i=1;i<9;i++)
        for (int j=1,rowsum=0;j<9;j++)
        {
            cin>>mp[i][j];
            rowsum +=mp[i][j];
            sum[i][j] += sum[i-1][j] + rowsum;
        }
    double result = n*fun(n-1,1,1,8,8)-sum[8][8]*sum[8][8];
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(result/(n*n))<<endl;
    return 0;
}
