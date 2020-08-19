#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;

//横坐标*纵坐标/2

string road;
int len,n;
double ans=0;
int h,z;
int anti=0;

int main(){
    cin>>n;
    while(n--){
        int h=0,z=0,anti=0;
        cin>>road;
        len=road.size();
        int cnt=0;
        while(len--)
        {
            if(road[cnt]=='U')
                z++;
            else if(road[cnt]=='R'){
                anti+=z;
                h++;
            }
            cnt++;
        }
        printf("%.3lf\n",(double)h*z/2-anti);
    }
}