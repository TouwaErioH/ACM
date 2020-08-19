/*
给出一个集合大小为n，要把内部的元素分成clusters（簇），每个簇至少大小为p
每个簇S均值S'为 ai求和/|S| |S|为簇S的size
每个簇的值为内部元素 (ai-S'^2)之和
求各个簇如何分，值之和最小
Each cluster contains consecutive number cluster内的数字是连续的

前面的分簇结果可以被后面利用
dp 状态转移方程: f[i]=min(f[i],f[j]+valuecluser[j+1][i])(i-j>=p)  //j+1...注意分界点 dp[0]=0.i in range p-1-N （编号为1-n）
//dp注意初始状态结束状态预处理。f[0]=0，f[i]初始为maxd
预处理：计算valuecluster[i][j]
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath> //pow
#include<algorithm> //min
using namespace std;

int T=0,casee=0,n,p,i,j,k;
const double maxd=1e15;    //2^16*2^16*100 2E11
double summ[105][105]; //存连续数字和
int nums[105];
double clustervalue[105][105];
double f[105]; //dp

double dp(){
    for(i=p;i<=n;i++)
        for(j=i-p;j>=0;j--){ //一开始写成i-p+1了...
            f[i]=min(f[i],f[j]+clustervalue[j+1-1][i-1]); //f[i]中元素编号+1，计算的时候注意减1
        }
    return f[n];
}

int main(){

    cin>>T;
    while(T--){
        cin>>n>>p;
        for(i=0;i<n;i++)
            cin>>nums[i];
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                {
                    if(i==j)
                    summ[i][j]=nums[i];
                    else
                    summ[i][j]=summ[i][j-1]+nums[j];
                }
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                {
                    clustervalue[i][j]=0;
                }
        for(i=0;i<n;i++)
            for(j=i+p-1;j<n;j++)
                {
                    double avg=summ[i][j]*1.0/(j-i+1);
                    for(k=i;k<=j;k++)
                    clustervalue[i][j]+=pow(nums[k]-avg*1.0,2);
                }
        for(i=1;i<=n;i++)
            f[i]=maxd;
        f[0]=0; //初始状态
        if(casee!=0)
            cout<<endl;
        casee++;
        printf("Case %d:\n",casee);
        printf("%.2lf\n",dp());
        
    }
    system("pause");
    return 0;
}