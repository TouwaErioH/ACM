#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char a[MAXN],b[MAXN];
int main()
{
    int n;
    long long s1,s2,s3,s4;
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    s1=s2=s3=s4=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]=='1'&&b[i]=='1')
            s1++;
        else if(a[i]=='0'&&b[i]=='0')
            s2++;
        else if(a[i]=='1'&&b[i]=='0')
            s3++;
        else if(a[i]=='0'&&b[i]=='1')
            s4++;
    }
    long long ans=s2*(s1+s3)+s3*s4;
    printf("%lld\n",ans);
    return 0;
}
