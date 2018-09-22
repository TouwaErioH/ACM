#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int k,n;
double l[10005];

bool solve(double x)
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
        num+=(int)(l[i]/x);
    }
    return num>=k;
}

int main()
{

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
    }
    double lf=0,rf=100050;
    for(int i=0;i<=100;i++)
    {
        double mid=(lf+rf)/2;
        if(solve(mid)) lf=mid;
        else rf=mid;
    }
    printf("%.2lf\n",floor(rf*100)/100);
}
