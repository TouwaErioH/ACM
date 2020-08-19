#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
map<int , int> :: iterator iter;
map<int , int> mapp ;
int x ;
int main()
{


    while(cin>>x&&x) 
    {
        mapp.insert(pair<int , int> (x,1));
    }
    for (iter = mapp.begin() ; iter != mapp.end() ; iter ++)
        cout<<iter -> first<<" ";
    return 0 ;
}