#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 9;
const int D = 16;
const int Inf = 9999999;

int dp[D][N][N][N][N];//存放切割为D个矩形的最小平方和
int s[N][N][N][N];//存方对应矩形总分的平方
int a[N][N];//矩阵方格中的值
int n;//要求切割的份数

int Sum(int x1,int y1,int x2,int y2)//计算该边界下的矩阵和的平方
{
 if(s[x1][y1][x2][y2]>0)
  return s[x1][y1][x2][y2];
 int ans=0;
 for(int i=x1;i<=x2;i++)
 {
  for(int j=y1;j<=y2;j++)
  {
   ans+=a[i][j];
  }
 }

 s[x1][y1][x2][y2]=ans*ans;
 return s[x1][y1][x2][y2];
}
int Divide(int n,int x1,int y1,int x2,int y2)//将以(x1,y1),(x2,y2)为边界的矩阵分割为n块并返回最小的平方和
{
 if(n==1)//不需要再往下分
 {
  if(dp[n][x1][y1][x2][y2]==-1)//未计算过
  {
      dp[n][x1][y1][x2][y2]=Sum(x1,y1,x2,y2);
  }

  return dp[n][x1][y1][x2][y2];
 }

 if(dp[n][x1][y1][x2][y2]!=-1)//已有计算
 {
  return dp[n][x1][y1][x2][y2];
 }
 int cnt = Inf;
 for(int i=x1;i<x2;i++)//横向切割
 {
  cnt=min(cnt,Divide(n-1,x1,y1,i,y2)+Sum(i+1,y1,x2,y2));
  cnt=min(cnt,Divide(n-1,i+1,y1,x2,y2)+Sum(x1,y1,i,y2));
 }
 for(int j=y1;j<y2;j++)
 {
  cnt=min(cnt,Divide(n-1,x1,y1,x2,j)+Sum(x1,j+1,x2,y2));
  cnt=min(cnt,Divide(n-1,x1,j+1,x2,y2)+Sum(x1,y1,x2,j));
 }
 dp[n][x1][y1][x2][y2]=cnt;
 return cnt;
}

int main()
{
 scanf("%d",&n);//输入切割数
 double sum=0.0;
 for(int i=1;i<N;i++)
 {
  for(int j=1;j<N;j++)
  {
   scanf("%d",&a[i][j]);
   sum=sum+a[i][j];
  }
 }
 sum/=n;
 memset(dp,-1,sizeof(dp));//记忆化保存，对于每种请况只需记录一次即可，值为-1时表示该情况尚未计算过
 memset(s,0,sizeof(s));//同上
     double ans = Divide(n,1,1,N-1,N-1);//分割矩形
    ans=sqrt(ans/n-sum*sum);
 printf("%.3lf\n",ans);
 return 0;
}

/*1.公式化简
  2.对于这个问题,要寻找的是使各个矩形的分数平方和最小的解决方案,
  沿用数学归纳法的思路,一个矩形的最优解决方案,必然是由组成它的某两个子矩形的最优解决方案得来的.
*/
