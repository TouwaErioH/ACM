/*
int x = p[n].x - p[m].x;
int y = p[n].y - p[m].y;
if((x<0&&y>0) || (x>0&&y<0)) ans = max(abs(x), abs(y));
else ans = abs(x+y);
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 10000;

struct Point
{
    int x, y;
    Point(int x=0, int y=0):x(x), y(y) {}
}p[maxn+1000];

int dx[] = {-1, -1, 0 , 1 , 1 , 0 };
int dy[] = {0 , 1 , 1 , 0 , -1, -1};
int pos;

void cal(int dir, int l)  
{
    pos++;
    while(l--)
    {
        p[pos] = Point(p[pos-1].x+dx[dir], p[pos-1].y+dy[dir]);
        pos++;
    }
    pos--;
}

void Init()
{
    p[2] = Point(1, -1);
    pos = 2;
    for(int l = 1; l <= 58; ++l)
    {
        for(int dir = 0; dir < 6; ++dir)
{
if(dir==4)
cal(dir,l+1);
else
            cal(dir, l);
}
    }
}

int main()
{
    Init();

    int n, m;
    while(scanf("%d%d", &n, &m) == 2 && n)
    {
        int x = p[n].x - p[m].x;
        int y = p[n].y - p[m].y;
        int ans;
        if((x<0&&y>0) || (x>0&&y<0)) 
        ans = max(abs(x), abs(y));
        else ans = abs(x+y);
        printf("The distance between cells %d and %d is %d.\n", n, m, ans);
    }

    return 0;
}