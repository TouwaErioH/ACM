 //��ʵ������С�������������ӵĳ˻���
 // ���������ֱ���������ӷֽ⣬�������ӱ����������У�������ҵ���С�������˻����ɡ�
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
            while(cur%j==0){            //�ֽ�������
                temp[flag++]=j;
                cur/=j;
            }
        }
        if(cur!=1)
        temp[flag++]=cur;               //���������ֱ�Ӵ���
        }
        if(flag<2)            //�����Ӹ���С��2���-1
        printf("-1\n");
        else{
            sort(temp,temp+flag);
            printf("%I64d\n",temp[0]*temp[1]);
        }
    }
    return 0;
}
