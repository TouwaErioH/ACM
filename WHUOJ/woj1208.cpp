
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=50005;
int code1[maxn],code2[maxn];
int n;
int main() {
	priority_queue<int,deque<int>,less<int> > pri_q;  //大顶堆
	while(cin>>n) {
		for(int i=0; i<n; i++)
			cin>>code1[i];
		sort(code1,code1+n);
		for(int i=0; i<n; i++) {
			cin>>code2[i];
			pri_q.push(code1[0]+code2[i]);
		}
		sort(code2,code2+n);
		for(int i=1; i<n; i++)
			for(int j=0; j<n; j++) {
				if(code1[i]+code2[j]>pri_q.top())  break;
				pri_q.pop();
				pri_q.push(code1[i]+code2[j]);
			}
		for(int i=0; i<n; i++) {
			code1[n-i-1]=pri_q.top();
			pri_q.pop();
		}
		cout<<code1[0];
		for(int i=1; i<n; i++)
			cout<<' '<<code1[i];
	}
	return 0;
}