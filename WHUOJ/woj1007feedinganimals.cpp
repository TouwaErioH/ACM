// 我一开始以为是并行，然后想了想例子，是串行，并且可以重用，
//就变成找每一列最小值加起来。（贪心）
//总的加起来不超过10000 不考虑溢出
//524288 KIB= 512MB 1s  遍历的话10000*8 肯定能过。
#include <iostream>
#include<vector>
using namespace std;

int maxtri[8][10005];  //全局变量直接为0

int main(){
    int n;
    int tmp=0;
    int sum=0;
    while(cin>>n){
        for(int i=0;i<8;i++){
            for(int j=0;j<n;j++)
                cin>>maxtri[i][j];
        }
        
        sum=0;
        for(int i=0;i<n;i++){
            tmp=maxtri[0][i];
            for(int j=1;j<8;j++)
                tmp=(tmp>maxtri[j][i])?maxtri[j][i]:tmp;   //注意加括号
            sum+=tmp;}
        cout<<sum<<endl;  
    }
    return 0;
}