#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int Map[20][20],cal[20][20],out[20][20];
int n,m;
int dir[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};

int fuc(int x,int y){       //(x,y)��״̬�ɱ���ĺڰ� + ��Χ����ķ�ת״̬����
    int temp = Map[x][y];

    for(int i = 0;i < 5;i ++){
        int xi = x+dir[i][0];
        int yi = y+dir[i][1];

        if(xi < 1 || xi > n || yi < 1 || yi > m)    continue;
        temp += cal[xi][yi];
    }
    return temp%2;
}
int solve(){
    for(int i = 2;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(fuc(i-1,j))      //����Ϸ�Ϊ��ɫ������Ҫ��ת
                cal[i][j] = 1;

    for(int i = 1;i <= m;i ++)      //���һ��ȫ��
        if(fuc(n,i))
            return -1;

    int res = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            res += cal[i][j];
    return res;                     //����ͳ��
}

int main()
{
    while(cin>>n>>m){
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                cin>>Map[i][j];

        int flag = 0;
        int ans = 0x3f3f3f3f;
        for(int i = 0;i < 1<<m;i ++){       //��һ�� 1<<m��״̬�������ƴ�0��ʼ���ֵ����С����
            memset(cal,0,sizeof(cal));

            for(int j = 0;j <m;j ++)      //���ö�����ö�ٵ�һ�����е����  �����ҵ���
                cal[1][m-j] = i>>j & 1; //�ж�j-1�Ƿ����ڼ���i  ����i=0011  ��0001�����У���ת������cal��1����m��Ϊ1
            int cont = solve();
            if(cont >= 0 && cont < ans){        //��ת��������
                flag = 1;
                ans = cont;
                memcpy(out,cal,sizeof(cal));   //cal��¼ÿ���㷭ת����
            }
        }
        if(!flag)
            cout<<"IMPOSSIBLE"<<endl;
        else{
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= m;j ++){
                    if(j != 1)  cout<<" ";
                    cout<<out[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
