#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;

int T=0,n=0;
string ans;
int main(){
    cin>>T;
	while(T--){
		cin>>n;
        ans=((n%14)==0)?"snoopy wins the game!":"flymouse wins the game!";
        cout<<ans<<endl;
		
	}
	return 0;
}