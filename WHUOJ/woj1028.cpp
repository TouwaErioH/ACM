//只能45度走，X,Y同增同减，只有差距为odd才可以到
//最近:相当于光线反射，把目的地对称到轴对面，也就是MAX(X1-X2,Y1-Y2)

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int t,n,x1,y11,x2,y2,diff,ccount=1;  //y1，又错了;Y11

int main()
{
	//freopen("in.txt","r",stdin);

	cin>>t;
	while(t--)
	{
		cout<<"Case "<<ccount<<":"<<endl;
		cin>>n>>x1>>y11>>x2>>y2;
		if((y11-y2+x1-x2)%2!=0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			if(fabs(y11-y2)<=fabs(x1-x2))
				diff=fabs(x1-x2);
			else
				diff=fabs(y11-y2);
				cout<<diff<<endl;
		}
		if(t)
			cout<<endl;
		ccount++;
	}
	ccount=1;
	return 0;
}
