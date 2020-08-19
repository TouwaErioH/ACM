#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

const int mxn=10005;
int words[mxn];
int n,ans;
int main()
{
    while(cin>>n)
    {
        ans=0;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d",&words[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n-i-1;j++)
            {
                if(words[j]>words[j+1])
                {
                    words[j]=words[j]^words[j+1];
                    words[j+1]=words[j]^words[j+1];
                    words[j]=words[j]^words[j+1];
                    ans++;
                }
            }
            printf("%d\n",ans);
    }
    return 0;
}