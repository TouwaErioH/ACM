#include <cstdio>
#include<algorithm>
using namespace std;
int ans[1000005],len,num;
void solve()
{
    int mint=0,maxt=0;
    for(int i=0;i<num;i++)
        mint=max(mint,min(ans[i],len-ans[i]));
    for(int i=0;i<num;i++)
        maxt=max(maxt,max(ans[i],len-ans[i]));
        printf("%d %d\n",mint,maxt);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(cas;cas!=0;cas--)   //��ʵ��������ģ�cas==0������while
    {
        scanf("%d%d",&len,&num);
        for(int i=0;i<num;i++)
            scanf("%d",&ans[i]);
        solve();
    }
    return 0;
}
