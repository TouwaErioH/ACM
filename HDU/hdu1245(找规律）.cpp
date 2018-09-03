/*
假设 tmp 是 n/i 的值，当n == 10的时候（取具体值）
当 tmp = 1 时，个数 是10/1 - 10/2 == 5个

当 tmp = 2 时，个数 是10/2 - 10/3 == 2个

当 tmp = 3 时，个数 是10/3 - 10/4 == 1个
…………
当 tmp = 10时，个数是10/10 - 10/11 == 1个
所以我们发现有个规律了，当tmp == i 的时候，我们要求的个数就是 10/i - 10/(i+1)，然后我们前1 — sqrt(n)个数的数值还是比较大的，但是数据范围变小了
暴力可以求出来，剩下的 sqrt(n)+1 — n个数中 数据范围还是比较大，但是 n/i 的数据范围介于 1 - sqrt(n)之间，所以用我们找出的规律可以求出来

*/
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
int main()
{
    int T;
    LL n;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        cin>>n;
        int m = sqrt(n);
        LL ret = 0;
        for(int i=1; i<=m; i++)
            ret += n/i;
        for(int i=1; i<=m; i++)
            ret += (n/i - n/(i+1))*i;
        if(m == n/m)                  //去重（当x/sqrt(x)=sqrt(x)
            ret -= m;
        cout<<"Case "<<cas<<": "<<ret<<endl;
    }
    return 0;
}
