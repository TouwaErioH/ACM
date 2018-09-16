#include<bits/stdc++.h>
using namespace std;
int code[8][1<<8];
int readchar(){
    while(1){
        int ch=getchar();
        if(ch!='\r'&&ch!='\n')
            return ch;
    }
}
int readint(int len){
    int v=0;
    while(len--)
        v=v*2+readchar()-'0';
    return v;
}
int readcode(){
    memset(code,0,sizeof(code));
    code[1][0]=readchar();//第一行
    for(int len=2;len<=7;len++)
        for(int i=0;i<(1<<len)-1;i++){
            int ch=getchar();
            if(ch==EOF)    return 0;   //结束
            if(ch=='\n'||ch=='\r')    return 1;
            code[len][i]=ch;
        }
    return 1;
}
int main(){
    while(readcode()){
        while(1){
            int len=readint(3);//读取长度编码
            if(len==0)    break;
            while(1){
                int v=readint(len);
                if(v==(1<<len)-1)    break;//==时说明是111
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}
