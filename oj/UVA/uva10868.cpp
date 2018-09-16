#include<bits/stdc++.h>
using namespace std;
double Eg,E,Ek,v2;
double k,l,s,w;
const double G=9.81;
int main()
{
    while(scanf("%lf%lf%lf%lf",&k,&l,&s,&w)==4&&w)
    {
        Eg=w*G*s;
        Ek=0.5*k*max(0.0,s-l)*max(0.0,s-l);
        E=Eg-Ek;
        
        v2=2*E/w;
        if(v2<0)
            printf("Stuck in the air.\n");
        else if(v2>100)
            printf("Killed by the impact.\n");
        else
            printf("James Bond survives.\n");
    }
    return 0;
}