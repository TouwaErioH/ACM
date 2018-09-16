/*
��һ����5����������д����������֮��   �����õ����⣬2+x��xΪ���������������ͣ�
��һ����2��ż������д����������֮��
*/
#include<iostream>
using namespace std;

bool isPrime(int x){
    if(x==1) return false;
    if(x==2) return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}


int main(){
    int x;
    while(cin>>x){
        if(x==2){
            cout<<1<<endl;
            continue;
        }
        if(x%2==0){
            cout<<2<<endl;
            continue;
        }
        if(isPrime(x)){
            cout<<1<<endl;
            continue;
        }
        if(isPrime(x-2)){
            cout<<2<<endl;
            continue;
        }
        cout<<3<<endl;
    }
    return 0;
}
