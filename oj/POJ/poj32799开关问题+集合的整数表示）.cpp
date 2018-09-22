#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int Map[20][20],cal[20][20],out[20][20];
int n,m;
int dir[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};

int fuc(int x,int y){       //(x,y)的状态由本身的黑白 + 周围五个的翻转状态决定
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
            if(fuc(i-1,j))      //如果上方为黑色，必须要翻转
                cal[i][j] = 1;

    for(int i = 1;i <= m;i ++)      //最后一行全白
        if(fuc(n,i))
            return -1;

    int res = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            res += cal[i][j];
    return res;                     //步数统计
}

int main()
{
    while(cin>>n>>m){
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                cin>>Map[i][j];

        int flag = 0;
        int ans = 0x3f3f3f3f;
        for(int i = 0;i < 1<<m;i ++){       //第一行 1<<m种状态，二进制从0开始，字典序从小到大
            memset(cal,0,sizeof(cal));

            for(int j = 0;j <m;j ++)      //利用二进制枚举第一行所有的情况  ，从右到左
                cal[1][m-j] = i>>j & 1; //判断j-1是否属于集合i  比如i=0011  ，0001在其中，翻转，所以cal【1】【m】为1
            int cont = solve();
            if(cont >= 0 && cont < ans){        //翻转次数最少
                flag = 1;
                ans = cont;
                memcpy(out,cal,sizeof(cal));   //cal记录每个点翻转次数
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
