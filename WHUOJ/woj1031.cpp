/*
I. Suppose friend ranked with i got x chocolates. Then friend ranked with i+1 should got chocolates no more than x+k chocolates
and no less than x chocolates where k is a positive integer.
II. No.1 friend should get no more than k chocolates.
III. It is even possible for some friends to get no chocolates.
IV. If possible, all chocolates should be distributed and none were left.

第一个人不超过k，j+1比j多不超过k,不少于j
如果能分完就分完
当前 i个巧克力，j个人，分法至少加上 i-u*j块巧克力的分法(j个人每个人u块还是符合条件)
1 1 1: 1
4 2 2: 2 2; 1 3;
5 3 2: 0 2 3; 1 1 3; 1 2 2;

*/

#include<map>
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

int i,j;
const int choc=505,fri=105,bitmax=35;
int n,m,k;
int dpans[choc][fri][bitmax];// bitmax: dpans max bits// dpans[m][n][k]=m个巧克力，n个人，结果的第k位

int main(){
    while(scanf("%d%d%d",&n,&m,&k)&&n&&m&&k){

    //init
    for(i=0;i<choc;i++)
       for(j=0;j<fri;j++)
            for(int p=0;p<bitmax;p++)
                dpans[i][j][p]=0;
        dpans[0][0][0]=dpans[0][0][1]=1; //只有0个巧克力，0个人，分法只有一种，长度为1

        for(i=0;i<=n;i++)
            for(j=1;j<=m;j++){
   	    	    dpans[i][j][0]=1; //dpans[i][j][1]已经初始化为0了
                for(int l=0;l<=k;l++)
 	                if(i>=l*j) //当前 i个巧克力，j个人，分法至少加上 i-u*j块巧克力的分法(j个人每个人u块还是符合条件)
                     { 
    int templen=0;
    if(dpans[i][j][0]>=dpans[i-l*j][j-1][0])
        templen=dpans[i][j][0];
    else
        templen=dpans[i-l*j][j-1][0];
 	
    //如果templen==dpans[i-l*j][j-1][0]，说明位数增加了
    if(templen==dpans[i-l*j][j-1][0])  
    	dpans[i][j][0]=templen;
    
     //加上i-l*j块巧克力的分法
    for(int p=1;p<=templen;p++)
 		dpans[i][j][p]+=dpans[i-l*j][j-1][p];

    //大于9，进位（好像做竖式一样,hh）
    for(templen=1;templen<=dpans[i][j][0];templen++)
    if(dpans[i][j][templen]>9){
        dpans[i][j][templen+1]+=dpans[i][j][templen]/10;
        dpans[i][j][templen]=dpans[i][j][templen]%10;
    }

    //当最高位不为0且比原来位数高，说明答案位数增加了
    if(dpans[i][j][templen]!=0&&templen>dpans[i][j][0])
        dpans[i][j][0]=templen;
    }
    }

    // len
    for(int len=dpans[n][m][0];len>=1;len--){   //temp表示输出的当前位，从高位到低位;可能很大所以用了;dpans[m][n][0]表示位数;
        cout<<dpans[n][m][len];
    }
    cout<<endl;
    }
    return 0;
}


/*
java biginteger写会简单些吧
*/