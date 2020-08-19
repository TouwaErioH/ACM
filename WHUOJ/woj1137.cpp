#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int m, n;
vector <int> flower;
int flow;
int main() {
    while(cin>>n>>m) {
        flower.clear();
        while(n--){
            cin>>flow;
            flower.push_back(flow);
        }
        sort(flower.begin(),flower.end());
        m = m/flower[0];
        cout<<m<<endl;
    }
    return 0;
}