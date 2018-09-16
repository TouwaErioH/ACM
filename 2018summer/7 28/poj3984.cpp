#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> P;
#define INF 0x7fffffff
char maze[5][5];
int sx,sy;
int gx,gy;
int d[5][5];
P fat[5][5];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
//求(sx,sy)到(gx,gy)的最短距离
int bfs()
{
    queue<P> que;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            d[i][j]=INF;
        }
    }
    que.push(P(sx,sy));
    d[sx][sy]=0;
    while(que.size()){
        P p=que.front();
        que.pop();
        if(p.first==gx&&p.second==gy) break;
        for(int i=0;i<4;i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
            if(0<=nx&&nx<5&&ny>=0&&ny<5&&maze[nx][ny]!='1'&&d[nx][ny]==INF){
                que.push((P(nx,ny)));
                fat[nx][ny]=p;//父节点
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
    return d[gx][gy];
}
void solve(P p)   //递归输出
{
    if(p.first==sx&&p.second==sy){
        cout<<"("<<sx<<", "<<sy<<")"<<endl;
        return;
    }
    else{
        solve(fat[p.first][p.second]);
        cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
    }
}
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>maze[i][j];
        }
    }
    sx=0;sy=0;
    gx=4;gy=4;
    int res=bfs();
    P p(gx,gy);
    solve(p);
    return 0;
}
