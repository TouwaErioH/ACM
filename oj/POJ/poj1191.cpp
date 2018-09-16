#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 9;
const int D = 16;
const int Inf = 9999999;

int dp[D][N][N][N][N];//����и�ΪD�����ε���Сƽ����
int s[N][N][N][N];//�淽��Ӧ�����ֵܷ�ƽ��
int a[N][N];//���󷽸��е�ֵ
int n;//Ҫ���и�ķ���

int Sum(int x1,int y1,int x2,int y2)//����ñ߽��µľ���͵�ƽ��
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
int Divide(int n,int x1,int y1,int x2,int y2)//����(x1,y1),(x2,y2)Ϊ�߽�ľ���ָ�Ϊn�鲢������С��ƽ����
{
 if(n==1)//����Ҫ�����·�
 {
  if(dp[n][x1][y1][x2][y2]==-1)//δ�����
  {
      dp[n][x1][y1][x2][y2]=Sum(x1,y1,x2,y2);
  }

  return dp[n][x1][y1][x2][y2];
 }

 if(dp[n][x1][y1][x2][y2]!=-1)//���м���
 {
  return dp[n][x1][y1][x2][y2];
 }
 int cnt = Inf;
 for(int i=x1;i<x2;i++)//�����и�
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
 scanf("%d",&n);//�����и���
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
 memset(dp,-1,sizeof(dp));//���仯���棬����ÿ�����ֻ���¼һ�μ��ɣ�ֵΪ-1ʱ��ʾ�������δ�����
 memset(s,0,sizeof(s));//ͬ��
     double ans = Divide(n,1,1,N-1,N-1);//�ָ����
    ans=sqrt(ans/n-sum*sum);
 printf("%.3lf\n",ans);
 return 0;
}

/*1.��ʽ����
  2.�����������,ҪѰ�ҵ���ʹ�������εķ���ƽ������С�Ľ������,
  ������ѧ���ɷ���˼·,һ�����ε����Ž������,��Ȼ�����������ĳ�����Ӿ��ε����Ž������������.
*/
