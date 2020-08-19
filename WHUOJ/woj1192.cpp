#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int binary[10];

void build(int a){
    for(int i=0;i<10;i++){
        binary[i]=0;
    }
    int j=0;
    while(a!=0){
	binary[j++]=a%2;
	a/=2;
    }
    return ;
}

int n,temp;
int res=0;
int main(){
	while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>temp;
                build(temp);
				res=binary[7]^binary[6]^binary[5]^binary[4]^binary[3]^binary[2]^binary[1]^binary[0];
				if(j!=0)
				    cout<<' ';
				cout<<res;
			} 
			cout<<endl;
		} 
	}
	return 0;
}