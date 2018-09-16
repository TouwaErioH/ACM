#include <cstdio>//1可以移动到任意位置
#include<iostream>
#include<cstring>
using namespace std;
char s1[100005],s2[100005];
int main(){
    int cnt=0,j=0;
    cin>>s1;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]=='1')
            cnt++;
        else s2[j++]=s1[i];
    }
    int i=0;
    while(s2[i++]=='0') putchar('0');
    i--;
    while(cnt--) putchar('1');
    while(i<j) putchar(s2[i++]);
    return 0;
}
