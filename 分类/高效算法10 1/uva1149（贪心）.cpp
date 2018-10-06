#include<iostream>
#include<algorithm>
using namespace std;
int a[100000+5];
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int left=0, right=n-1, ans = 0;
		while(left <= right){
			if(a[right]+a[left] > m)
                right--;
			else
			right--, left++;
			ans++;
		}
		if(t)
		cout<<ans<<endl<<endl;
		else
            cout<<ans<<endl;
	}
	return 0;
}

