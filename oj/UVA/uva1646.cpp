#include<bits/stdc++.h>        //û�й�����ı߼�������n=3��4��n=4,7;n=5,11;
using namespace std;

int F[10001][2500];//0��ʾλ����֮��1-n��ʾ��λ

int main(){
	memset(F,0,sizeof(F));
	F[3][1]=4;F[3][0]=1;
	F[4][1]=7;F[4][0]=1;
	for(int i=5;i<=10000;i++){
		int carry=0;//��λ
		for(int j=1;j<=F[i-1][0];j++){
			F[i][j]=F[i-1][j]+F[i-2][j]+carry;//ģ��ӷ�����
			carry=F[i][j]/10;
			F[i][j]%=10;
		}
		F[i][0]=F[i-1][0];
		if(carry){
			F[i][F[i-1][0]+1]++;
			F[i][0]++;
		}
	}
	int n;
	while(cin>>n){
		for(int i=F[n][0];i>=1;i--){
			printf("%d",F[n][i]);
		}
		printf("\n");
	}

	return 0;
}
