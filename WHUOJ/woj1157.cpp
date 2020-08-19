#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int ans=0;
int cnt=0;
int cas=1;
int temp;
int main(){

	while(cin>>n&&n!=-1){
		ans=0;
        cnt=0;
		for(int i=0;i<n;i++){
            cin>>temp;
			if(temp ==1)
			    cnt++;
			else
			    ans=ans+cnt;
		}
		printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}