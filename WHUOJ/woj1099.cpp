// fn=2*fn-1 + 1  注意n从0开始
//快速幂
#include<map>
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

int binaryPow(int a, int b, int c){

	if(b == 0)
		return 1;
	else if(b % 2 == 1)
		return a * binaryPow(a, b - 1, c) % c;
	else{
		int num = binaryPow(a, b/2, c) % c; 
		return num * num % c;
	}
	
}

int n,m,fans;

int main(){
	while(cin>>n>>m){
		if(n==0)
        {
        cout<<0<<endl;
        continue;
        }
		fans=binaryPow(2,n,m);
        fans=(fans==0)?m-1:fans-1;
		cout<<fans<<endl;
	}
	return 0;
}