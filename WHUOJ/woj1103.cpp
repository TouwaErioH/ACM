#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;


//win +1  lose -1 ;
//直接求 x*x+x*x*(x-1)+....
// 推： 因为获胜，所以：f[2] = 1 , f[-2] = 0。f[i] = f[i+1]*p + f[i-1]*(1-p)。求f[0]
int  T,pos;
double poss;
char useless;
double ans;
int main(){
    cin>>T;
    while(T--){
        cin>>pos>>useless;
        poss=(double)pos;
        poss=poss/100;
        ans=poss*poss/(2*poss*poss+1-2*poss)*100;
        printf("%.2lf",ans);
        cout<<'%'<<endl;
    }
	return 0;
}