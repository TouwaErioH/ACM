#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;

map<int,int>books;
int m,n;
int main(){
    while(cin>>m){
        books.clear();
        while(m--){
            cin>>n;
            books[n]++;
        }

    map<int,int>::iterator iter=books.begin();
    for(iter;iter!=books.end();iter++)
    cout<<iter->first<<' ';
    cout<<endl;
	}

	return 0;
}
