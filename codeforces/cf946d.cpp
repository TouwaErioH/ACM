#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=505;
const int INF=0x3f3f3f3f;

char s[N][N];
int num[N],pos[N][N],dp[N],v[N][N];  //pos[i][j]��Ӧ��i���ַ�����j��'1'��λ�ã�num[i]��¼��i���ַ���'1'������
                                     //v[i][k]����i���ַ���ɾ��k��1�����е�ʱ��
int main(){
    int n,m,lim;
    scanf("%d%d%d",&n,&m,&lim);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++){
            if(s[i][j]=='1'){
                num[i]++;
                pos[i][num[i]]=j;
            }
        }
    }
    //�����v[i][k],
    for(int i=0;i<n;i++){
        //ö��k
        for(int k=0;k<=min(num[i]-1,lim);k++){
            int res=INF;
            for(int p=0;p<=k;p++){
            res=min(res,pos[i][num[i]-k+p]-pos[i][p+1]+1);//����λ-����λ
            }
            v[i][k]=m-res;
        }
        v[i][num[i]]=m;
    }
    //���鱳��
    memset(dp,0,sizeof(dp));//dpΪ����ѧ��ʱ��
    for(int i=0;i<n;i++){
        for(int j=lim;j>=0;j--){
            for(int k=0;k<=min(j,m);k++){
                dp[j]=max(dp[j],dp[j-k]+v[i][k]);
            }
        }
    }
    printf("%d\n",m*n-dp[lim]);
    return 0;
}
