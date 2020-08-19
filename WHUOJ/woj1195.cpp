#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
/*
注意到只有两行，那么可以用f[i][j]表示第一行到i，第二行到j的状态总数，
因为i和j相差超过2是没有意义的(因为超过2的话短的那行一定只能用1*2插入进去，
所以可以简化状态f[i][j]表示下面一行到i，上面一行与其相差j的方法总数(-2<=j<=2),转移方程应该很好推

*/
const int maxn=1000005;
int n;
int offline[maxn][4];

void build(){
	offline[1][3]=1,offline[2][2]=1,offline[2][1]=1,offline[2][0]=1;
	offline[2][3]=2;
	for(int i=3;i<maxn;i++)
	{
		offline[i][3]=(offline[i-1][0]+offline[i-1][1]+offline[i-1][2]+offline[i-1][3])%10000;
		offline[i][1]=(offline[i-1][0]+offline[i-1][2])%10000;
		offline[i][2]=(offline[i-1][0]+offline[i-1][1])%10000;
		offline[i][0]=offline[i-1][3];
	}
}

int main()
{
    build();
	while(cin>>n){
        cout<<offline[n][3]<<endl;
    }
	return 0;
}