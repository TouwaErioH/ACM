//1.˼ά���������λ�ò��䣻2.����ľ�����޳����Ͳ��ÿ��ǵ���ȥ3.����ʱ��һ����˳������Ҫ��order
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
        sort(before,before+n);    //����sort�ˣ��ı���˳������Ҫorder
        for(i=0;i<n;i++)
            order[before[i].id]=i;   //ԭ����id��������iλ
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
