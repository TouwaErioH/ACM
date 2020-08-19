#include<map>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string ans;
int t;
bool start;
int main(){
	int len;
	cin>>t;
    getchar();
	while(t--){
		//cin>>ans;
        getline(cin,ans);
		len=ans.size();
		if(ans[0]>='a'&&ans[0]<='z')
				ans[0]=ans[0]-'a'+'A';
        start=false;
		for(int i=1;i<len;i++){
			if(ans[i]==' '){
				i++;
                start=true;
			}else 
            {
            //if(ans[i]>='A'&&ans[i]<='Z'&&start==false)
            if(ans[i]>='A'&&ans[i]<='Z'&&ans[i-1]!=' ')
			ans[i]=ans[i]-'A'+'a';
            start=false;
            }

		}
		cout<<ans<<endl;
	}
    system("pause");
	return 0;
}
