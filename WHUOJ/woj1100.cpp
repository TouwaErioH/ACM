//6个人名字前两个字母都不同且无覆盖。直接看两个字符然后跳转.O(N)

#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;


vector<string>names={"littleken", "knuthocean", "dongfangxu", "zap", "kittig", "robertcui", "forest", "flirly"};
vector<string>pre={"li","kn","do","za","ki","ro","fo","fl"};
int dis[8]={9,10,10,3,6,9,6,6};
int cnt[8];
string s;
int T;
int maxn,out;

int main(){
    cin>>T;
    while(T--){
        maxn=-1;
        out=0;
        for(int i=0;i<8;i++)
            cnt[i]=0;
        cin>>s;
        for(int i=0;i<s.size();){
            for(int j=0;j<8;j++){
                if(s[i]==pre[j][0]&&s[i+1]==pre[j][1]){
                    cnt[j]++;
                    i=i+dis[j];
                    //out=maxn>dis[j]?out:j;
                    break;
                }
            }
        }
        for(int i=0;i<8;i++){
            out=(maxn>=cnt[i])?out:i;
            maxn=maxn>cnt[i]?maxn:cnt[i];
        }
        cout<<names[out]<<endl;

    }
    return 0;
}