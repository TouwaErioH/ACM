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
若x=a^m*b^n(a,b为质数)
任取约数y,有y=a^p*b^q(p为0-m整数,q为0-n整数)
则x有（m+1）*（n+1）个约数
所以,若x有奇数个因数,则
x=a^p*b^q*···（p,q···均为偶数）
换句话说,x一定是完全平方数
x为完全平方数即1,4,9···31^2（32^2=1024>1000）共31个
*/


int offline[105];

void build(){
    for(int i=1; i<101; i++) {
		offline[i]=i*i;
	}
}

int n,ans;
int main() {
    build();
	while(cin>>n) {
        ans=-1;
		for(int i=1;i<101;i++){
            if(n>=offline[i])
                ans=i;
            else
                break;
        }
        if(ans==-1)
        ans=0;
		cout<<ans<<endl;
    }
	return 0;
}