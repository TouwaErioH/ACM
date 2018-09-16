//在维持中位数的前提下，降低sum
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN = 1005;
int num[MAXN];

int main()
{
    int n, k, p, x, y, sum = 0, big = 0, small = 0,cnt=0;
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    for (int i = 0; i < k; ++i)
    {
        cin >> num[i];
        sum += num[i];
        if (num[i] < y) ++small;
        else if (num[i] > y) ++big;
        else ++cnt;
    }
    if(small>n/2)            //读错题了，最小中位数。。
      {
          cout<<-1<<endl;
      }
    else
    {
    int addsmall=min(n-k,max(0, (n / 2 - small)));
    int addbig =n-k-addsmall;
    sum = sum + addsmall+ addbig* y;

    if (sum > x) cout << -1;
    else
    {
        for (int i = 0; i < addbig; ++i)
            cout << y << ' ';
        for (int i = 0; i < addsmall; ++i)
            cout << 1<<' ';
    }
    cout << '\n';
   }
    return 0;
}
