
//预处理每个点x，是否为i的名字结束；若是 f[X][i]=f[X-lenth][i]+1.取max比较
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;


int T;

string name1="dongfangxu";
string name2="zap";
string s;
bool is[2][100005];

int max1,max2;
int dp[2][100005];
void init(){
    for(int i=0;i<s.size();i++)
    {
        is[0][i]=is[1][i]=false;
        dp[0][i]=dp[1][i]=0;
    }
    for(int i=2;i<s.size();i++)
        {
            if(i>8){
                if((s.substr(i-9,10)==name1)){  //substr是长度，当成范围了
                    is[0][i]=true;
                }
            }
            if((s.substr(i-2,3)==name2)){
                is[1][i]=true;
            }
        }

}

int main()
{
    cin>>T;
    while(T--)
    {
        max1=0,max2=0;
        cin>>s;
        
        init();
        
        for(int i=2;i<s.size();i++){
            if(is[1][i]){
                dp[1][i]=dp[1][i-3]+1;
                max2=max2>dp[1][i]?max2:dp[1][i];
            }
            if(i>8){
                if(is[0][i]){
                    dp[0][i]=dp[0][i-10]+1;
                    max1=max1>dp[0][i]?max1:dp[0][i];
                }
            }
        }
        
        if(max2<=max1)
        printf("dongfangxu!\n");
        else
        printf("zap!\n");
        cout<<max1<<max2<<endl;
        }
        system("pause");
    return 0;
}