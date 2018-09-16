    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll C(int n,int k);

    int main()         //ÕâÌâÍµÀÁÁË
    {
        int n,k;
        while(scanf("%d%d",&n,&k)!=EOF)
        {
            if(k==1) printf("1\n");
            else if(k==2)
                printf("%lld\n",C(n,2)+1);
            else if(k==3)
                printf("%lld\n",C(n,2)+1+C(n,3)*2);
            else
                printf("%lld\n",C(n,2)+1+C(n,3)*2+C(n,4)*9);
        }
        return 0;
    }

    ll C(int n,int k)
    {
     ll ans=1;
    for(int i=n;i>=n-k+1;i--)
    {
        ans*=i;
    }
    for(int i=1;i<=k;i++)
    {
        ans/=i;
    }
      return ans;
    }
