#include<iostream>
#include<cstdio>
using namespace std;
int n;
char str[2005];
void solve()
{
    int l=0,r=n-1,cnt=0;
    while(l<=r)
    {
        int flag=0;
        for(int i=0;i+l<=r;i++)
        {
            if(str[i+l]<str[r-i])
            {
                flag=1;
                break;
            }
            else if(str[i+l]>str[r-i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<str[l++];
        else
            cout<<str[r--];
        cnt++;
        if(cnt==80)
        {
            cout<<endl;
            cnt=0;
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
       for(int i=0;i<n;i++)
        cin>>str[i];
        solve();
    }
    return 0;
}
