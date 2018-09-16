//�����������˺þò�������ʲô������ļ���M�ַ�����ÿһ�ж���M+2�ַ������һ��M�ַ�
//ÿ�����60�ַ�
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxcol=60;
const int maxn=105;
string filenames[maxn];

//����ַ���s,���Ȳ���lenʱ���ַ�extra
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
            m=max(m,(int)filenames[i].length());//STL��max
        }
        //��������cols������rows
        int cols=(maxcol-m)/(m+2)+1;
        int rows=(n-1)/cols+1;//���һ�м�һ��(��ֹ��������)��������(����)���ټ�һ����
        print("",60,'-');
        cout<<"\n";
        sort(filenames,filenames+n);//����
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
