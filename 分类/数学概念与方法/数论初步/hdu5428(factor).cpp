 //其实就是最小的两个素数因子的乘积。
 // 将各个数分别进行质因子分解，将质因子保存在数组中，排序后找到最小的两个乘积即可。
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    long long i,j,cur;
    int t,n,flag;
    long long temp[1005];
    scanf("%d",&t);
    while(t--){
        flag=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
        scanf("%I64d",&cur);
        for(j=2;j*j<=cur;j++){
            while(cur%j==0){            //分解质因子
                temp[flag++]=j;
                cur/=j;
            }
        }
        if(cur!=1)
        temp[flag++]=cur;               //如果是质数直接存上
        }
        if(flag<2)            //质因子个数小于2输出-1
        printf("-1\n");
        else{
            sort(temp,temp+flag);
            printf("%I64d\n",temp[0]*temp[1]);
        }
    }
    return 0;
}
