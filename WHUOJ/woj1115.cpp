#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;



const int len=15;
vector <char>alpha={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int ans[len];
int r,c;
int cnt=0;
int main(){

    while(scanf("R%dC%d%*c",&r,&c)&&!(!r&&!c)){
        cnt =0;
        while(c){
            ans[cnt++]=c%26;
            if(!ans[cnt-1]){
                ans[cnt-1]=26;
                c--;
            }
            c=c/26;
        }
        for(int i=cnt-1;i>=0;i--)
            cout<<alpha[ans[i]-1];
            cout<<r<<endl;
    }
    return 0;
}