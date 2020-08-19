// 分组，用map
#include<map>
#include<iostream>

using namespace std;
map<int,int>building;
int main(){
	int t,n,i,ans=0;

	cin>>t;
	while(t--){
        building.clear();		ans=0;
		cin>>n;
		while(n--){
			cin>>i; 
			building[i]++;
            ans=ans>building[i]?ans:building[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
		map<int,int>::iterator iter;
		for(iter=building.begin();iter!=building.end();++iter)
			ans=iter->second>ans?iter->second:ans;
*/