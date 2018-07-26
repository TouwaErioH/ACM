#include<iostream>
#include<set>
#include<cstdio>
using namespace std;

int main()
{
    set<int> s;
    int num=0;
    char c;int k,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c>>k;
        if(c=='+')
        {
            s.insert(k);
            int l=s.size();
            num=max(l,num);
        }
        else
        {
            if(s.find(k)==s.end())
                num++;
            else
                s.erase(k);
            int l=s.size();
            num=max(l,num);
        }
    }
    cout<<num<<endl;
    return 0;
}
