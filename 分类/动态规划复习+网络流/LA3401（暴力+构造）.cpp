#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int maxn = 4;
int N,dice[maxn][6],ans;
vector<string> names;
int dice24[24][6];
int r[maxn],color[maxn][6];

int Left[] = {4,0,2,3,5,1};
int Up[] = {2,1,5,0,4,3};
void rot(int T[],int p[])
{
    int q[6];
    memcpy(q,p,sizeof(q));
    for (int i = 0; i < 6; i++)
        p[i] = T[q[i]];
}

void enumerate()
{
    int p0[6] = {0,1,2,3,4,5};
    int times = 0;
    for (int i = 0; i < 6; i++)
    {
        int p[6];
        memcpy(p,p0,sizeof(p0));
        if (i == 0) rot(Up,p);
        if (i == 1)
        {
            rot(Left,p);
            rot(Up,p);
        }
        if (i ==3)
        {
            rot(Up,p);
            rot(Up,p);
        }
        if (i == 4)
        {
            rot(Left,p);
            rot(Left,p);
            rot(Left,p);
            rot(Up,p);
        }
        if (i == 5)
        {
            rot(Left,p);
            rot(Left,p);
            rot(Up,p);
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                dice24[times][k] = p[k];
            }
            rot(Left,p);
            times++;
        }
    }
}

int get_ID(string name)
{
    int n = names.size();
    for (int i = 0; i < n; i++)
    {
        if (names[i] == name)
            return i;
    }
    names.push_back(name);
    return n;
}

void check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            color[i][dice24[r[i]][j]] = dice[i][j];
        }

    }
    int tot = 0;
    for (int j = 0; j < 6; j++)
    {
        int cnt[maxn*6];
        memset(cnt,0,sizeof(cnt));
        int maxface = 0 ;
        for (int i = 0; i < N; i++)
        {
            maxface = max(maxface,++cnt[color[i][j]]);
        }
        tot += N - maxface;
    }
    ans = min(ans,tot);
}

void dfs(int d)
{
    if (d == N) check();
    else
    {
        for (int i = 0 ; i < 24; i++)
        {
            r[d] = i;
            dfs(d+1);
        }
    }
}

int main()
{
    enumerate();
    while (cin>>N && N)
    {
        names.clear();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                string name;
                cin>>name;
                dice[i][j] = get_ID(name);
            }
        }
        ans = N*6;
        r[0] = 0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
