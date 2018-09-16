#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int>cs,as;

int main()
{
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cs.push(a);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a;
		as.push(a);
	}
	int sum=0;
	while(!q1.empty()&&!q2.empty())
	{
		int b=q1.front(),c=q2.front();
		if(b<=c){
			cs.pop();
			as.pop();
			sum++;
		}
		else {
			cs.pop();
		}
	}
	cout<<sum<<endl;
	return 0;
}
