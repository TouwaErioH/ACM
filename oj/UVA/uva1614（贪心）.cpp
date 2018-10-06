#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100005;

struct node{
int x,id;
}
a[maxn];
int ans[maxn];
bool cmp(node x,node y) {return x.x>y.x;}

int main()
{
    int n;
    int sum;
    while (scanf("%d",&n)==1)
    {
      long long sum=0;
      for (int i=1;i<=n;i++)
      {
        scanf("%d",&a[i].x);
        a[i].id=i;
        sum+=a[i].x;
      }
      if (sum%2)
      {
      printf("No\n");
      continue;
      }
      printf("Yes\n");
      sum/=2;
      sort(a+1,a+1+n,cmp);
      for (int i=1;i<=n;i++)
      {
        if (a[i].x<=sum)
        {ans[a[i].id]=1;
        sum-=a[i].x;
        }
        else
            ans[a[i].id]=-1;
      }
      printf("%d",ans[1]);
      for (int i=2;i<=n;i++)
        printf(" %d",ans[i]);
      cout<<endl;
    }
    return 0;
}
