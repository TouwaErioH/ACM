#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
set<int> Ws;
set<int> Hs;
multiset<int> wms;
multiset<int> hms;

int main()
{
    int w,h,n;
    scanf("%d%d%d",&w,&h,&n);
    Ws.insert(0);
    Ws.insert(w);
    Hs.insert(0);
    Hs.insert(h);
    wms.insert(w);
    hms.insert(h);
    for(int i=0; i<n; i++)
    {
        char op;
        int x;
        getchar();
        scanf("%c%d",&op,&x);
        if(op=='H')
        {
            Hs.insert(x);
            int a=*(--Hs.find(x));
            int b=*(++Hs.find(x));
            hms.erase(hms.find(b-a));
            hms.insert(x-a);
            hms.insert(b-x);
        }
        else
        {
            Ws.insert(x);
            int a=*(--Ws.find(x));
            int b=*(++Ws.find(x));
            wms.erase(wms.find(b-a));
            wms.insert(x-a);
            wms.insert(b-x);
        }

        long long maxh=*(--hms.end());
        long long maxw=*(--wms.end());
        printf("%I64d\n",maxh*maxw);
    }

    return 0;
}
