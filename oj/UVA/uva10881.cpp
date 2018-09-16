//1.思维，蚂蚁相对位置不变；2.假设木棍无限长，就不用考虑掉下去3.输入时不一定按顺序，所以要有order
#include<iostream>
using namespace std;
#include<algorithm>
#include<stdio.h>
const int maxn=10005;
struct ant
{
    int id;
    int p;
    int d;
    bool operator <(const ant &a) const {return p<a.p;}
}before[maxn],after[maxn];
const char dirName[][10]={"L","Turning","R"};
int order[maxn];
int main()
{
    int N;
    int L,T,n;
    int i,j,k;
    cin>>N;
    k=1;
    while(N--)
    {
        scanf("%d%d%d",&L,&T,&n);
        for(i=0;i<n;i++)
            {
                int p;
                char c;
                scanf("%d %c",&p,&c);
                int d=(c=='L'?-1:1);
                before[i]=ant{i,p,d};
                after[i]=ant{0,p+d*T,d};
            }
        cout<<"Case #"<<k++<<":"<<endl;
        sort(before,before+n);    //这里sort了，改变了顺序，所以要order
        for(i=0;i<n;i++)
            order[before[i].id]=i;   //原来第id个现在在i位
        sort(after,after+n);
        for(i=0;i<n-1;i++)
            if(after[i].p==after[i+1].p)after[i].d=after[i+1].d=0;
        for(i=0;i<n;i++)
        {
            int m=order[i];
            if(after[m].p<0||after[m].p>L)cout<<"Fell off"<<endl;
            else cout<<after[m].p<<" "<<dirName[after[m].d+1]<<endl;
        }
      cout<<endl;
    }
    return 0;
}
