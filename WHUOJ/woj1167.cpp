#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
// 挑战程序设计竞赛原题

int direx[8] = { 0, 1, -1, 1, -1, 0, -1, 1 };
int direy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };

const int maxn=105;
char mapp[maxn][maxn];

int nextposx,nextposy;

void dfs(int x, int y,int r, int c)
{
    if (x<c&&x >= 0 && y<r&&y >= 0)
        if (mapp[y][x] == 'O')
        {
            mapp[y][x] = 'X';
            for (int i = 0; i<8; i++)
            {
                nextposx = x + direx[i];
                nextposy = y + direy[i];
                dfs(nextposx,nextposy,r,c);
            }
        }
}

int r, c;
int ans;

int main()
{
    int ans;
    while (cin >> r >> c)
    {
        if(r==0&&c==0)
            break;
        ans = 0;
        for (int i = 0; i<r; ++i)
            for (int j = 0; j<c; ++j)
                cin >> mapp[i][j];
        for (int i = 0; i<r; ++i)
            for (int j = 0; j<c; ++j)
                if (mapp[i][j] == 'O')
                {
                    ans++;
                    dfs(j,i,r,c);
                }
        printf("%d\n",ans);
    }
    return 0;
}