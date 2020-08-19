#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

const double pi=3.1415;
double D,H;
double myalpha,mybeta,mygamma,tanmyalpha,tanmybeta,tanmygamma;
double res=0;

void calcu(){
        tanmyalpha=tan(myalpha/180.0*pi);
        tanmybeta=tan(mybeta/180.0*pi);
        tanmygamma=tan(mygamma/180.0*pi);
        res=D*sqrt(2.0/(1.0/tanmyalpha/tanmyalpha+1.0/tanmygamma/tanmygamma-2.0/tanmybeta/tanmybeta))+H;
}

int main()
{
    cin>>D>>H;
    while(cin>>myalpha>>mybeta>>mygamma&&myalpha&&mybeta&&mygamma)
    {
        calcu();
        res=(res-(int)res<0.5)?(int)res:((int)res+1);
        cout<<res<<endl;
    }
    return 0;
}