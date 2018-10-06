#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> a,ans;
int main(){
    while(~scanf("%d",&n)&&n){
        a.clear(),ans.clear();
        for(int i=0;i<n;++i){
            int k;
            scanf("%d",&k);
            a.push_back(k);
        }
        while(1){
            if(a[0]==1){   //判断已经有了解
                bool ok=true;
                for(int i=0;i<n;++i)
                    if(a[i]!=i+1){ok=false;break;}
                if(ok) break;
            }
            if(a[0]<a[1]||(a[1]==1&&a[0]==n)){//注意有特例。如51423会循环
                ans.push_back(2);
                a.insert(a.begin(),a[n-1]);
                a.erase(a.end()-1);
            }
            else{
                ans.push_back(1);
                swap(a[0],a[1]);
            }
        }
        for(int i=ans.size()-1;i>=0;--i)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
