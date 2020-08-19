#include <iostream>
#include <string>
#include<cctype>
using namespace std;

// 考虑换行.最后 .和字母在一起不考虑。cin空格截断，刚好

int main (){
    int first=1,cnt=0;
    string s;
    while(cin>>s){  //EOF   考虑换行,换行后输出上一组的cnt.first=1表示第一行
        if(isdigit(s[0])){
            if (first)
            { cout<<s<<" "; first=0;}
            else{
            cout<<cnt<<endl; cnt=0;cout<<s<<" "; }
        }
        else if(isalpha(s[0])) cnt++;   //s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')
    }
    cout<<cnt<<endl;  //EOF
    return 0;
}