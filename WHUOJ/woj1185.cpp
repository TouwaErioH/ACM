#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
/*
f[i][j]表示把i个球放进j个盒子里的方法总数，若没有空盒子，那么f[i][j]=f[i-j][j]（把所有盒子里的球加一个）
,若有空盒子，不妨让最后一个盒子变成空盒子，f[i][j]=f[i-1][j]。预处理出所有的结果，直接查表即可。
*/

const int maxn=105;
int m,n;
long long f[maxn][maxn];
void build()
{
    f[0][0]=1;
    for(int i=1;i<maxn;i++)
        for(int j=1;j<=i;j++)
            if(i<=2*j)
                f[i][j] =f[i-j][i-j]+ f[i][j-1] ;
            else
                f[i][j] = f[i-j][j]+f[i][j-1] ;
}

int main()
{

    build();
    while(cin>>m>>n)
    {
        if(m<=n)
            cout<<f[m][m]<<endl;
        else
            cout<<f[m][n]<<endl;
    }
    return 0;
}