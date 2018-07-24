//这道题输出读了好久才明白是什么。最长的文件名M字符，则每一列都是M+2字符，最后一列M字符
//每行最多60字符
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxcol=60;
const int maxn=105;
string filenames[maxn];

//输出字符串s,长度不足len时补字符extra
void print(const string& s,int len,char extra){
    cout<<s;
    for(int i=0;i<len-s.length();i++)
        cout<<extra;
}

int main(){
    int n;
    while(cin>>n){
        int m=0;
        for(int i=0;i<n;i++){
            cin>>filenames[i];
            m=max(m,(int)filenames[i].length());//STL的max
        }
        //计算列数cols和行数rows
        int cols=(maxcol-m)/(m+2)+1;
        int rows=(n-1)/cols+1;//最后一行减一个(防止正好填满)，除以列(整型)，再加一正好
        print("",60,'-');
        cout<<"\n";
        sort(filenames,filenames+n);//排序
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                int idx=c*rows+r;
                if(idx<n)
                    print(filenames[idx],c==cols-1?m:m+2,' ');
            }
            cout<<"\n";
        }
    }
    return 0;
}
