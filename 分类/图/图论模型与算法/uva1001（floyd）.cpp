#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int INF = 1000000;

int n;
double d[105][105];
int x[105], y[105], z[105], r[105];

void Floyd()
{
    for (int k = 1; k <= n+2;k++)
    for (int i = 1; i <= n+2;i++)
    for (int j = 1; j <= n+2; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    //freopen("D:\\txt.txt", "r", stdin);
    int kase = 0;
    while (cin>>n && n!=-1)
    {
        for (int i = 1; i <= n + 2;i++)
        for (int j = 1; j <= n + 2;j++)
        if (i == j)  d[i][j] = 0;
        else d[i][j] = INF;

        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i] >> z[i] >> r[i];
        for (int i = n + 1; i <= n + 2; i++)
        {
            cin >> x[i] >> y[i] >> z[i];
            r[i] = 0;
        }

        for (int i = 1; i <= n + 2;i++)
        for (int j = 1; j <= n + 2; j++)
        {
            if (i == j)  continue;
            double dis = sqrt((x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]) + (z[j] - z[i])*(z[j] - z[i]));
            dis = dis - r[j] - r[i];
            if (dis < 0)  dis = 0;
            d[i][j] = dis;
        }
        Floyd();
        printf("Cheese %d: Travel time = %.f sec\n", ++kase, 10 * d[n+1][n+2]);
    }
}
