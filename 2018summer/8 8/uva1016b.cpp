#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,m,q;
int a[1005];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    cin>>s;
    cin>>t;
    for(int i=0;i<=n-m+1;i++)
        if(s.substr(i,m)==t)
            a[i]=1;
    while(q--)
    {
        int l,r,ans=0;
        cin>>l>>r;
        if(r-l+1<m)
            puts("0");
        else
        {
        l--;
        r--;
        for(int i=l;i<=r-m+1;i++)
            if(a[i]) ans++;
        cout<<ans<<endl;
        }
    }
    return 0;
}
