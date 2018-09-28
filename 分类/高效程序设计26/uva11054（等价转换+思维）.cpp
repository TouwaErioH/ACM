#include <iostream>
#include<cmath>
using namespace std;

int main(){
int n;
while(cin>>n&&n)
{
long long ans=0,a,last=0;
for(int i=1;i<=n;i++)
{
cin>>a;
last+=a;
ans+=abs(last);
}
cout<<ans<<endl;
}
return 0;
}
