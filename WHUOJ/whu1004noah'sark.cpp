// meters =100 cm  1 inch= 2.54cm  feet=0.3048 m  cubits 45.72cm
// meters/centimeters/inches/cubits/feet 
#include<iostream>
#include <cmath>
const double eps=1e-9;

using namespace std;

//l==w 则spin。否则， Its length to width ratio of exactly six to one provided excellent stability on the high seas.
// fbs abs 求绝对值 cmath

double trans(double l,string unit){
    if (unit[2]=='t')
        l*=100;
    else if(unit[2]=='c')
        l*=2.54;
    else if(unit[2]=='b')
        l*=45.72;
    else if(unit[2]=='e')
        l*=30.48;
    return l;
}

int main(){
    string l,w,h;
    int flag=0;
    double ll,ww,hh;
    while(cin>>ll){
        cin>>l>>ww>>w>>hh>>h;
        /*
        if(!flag)
            flag=1;
        else
            cout<<endl;
            */
        ll=trans(ll,l);
        ww=trans(ww,w);
        if(fabs(ll-ww)<eps)
            cout<<"Spin"<<endl;
        else if(fabs(ll-6.0*ww)<eps)   // 考虑 /0。之前先判断==0，没考虑全。
            cout<<"Excellent"<<endl;
        else
            cout<<"Neither"<<endl;
            cout<<endl;

    }
    return 0;
}