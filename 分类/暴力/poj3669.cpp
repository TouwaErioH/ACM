#include <cstdio>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int, int> P;
const int MAX_M = 50000;
const int MAX_N = 305;
const int INF = 100000000;
int M;
int X[MAX_M], Y[MAX_M], T[MAX_M];
int maze[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(){
    if(maze[0][0] == 0) return -1;
    queue<P> que;
    que.push(P(0, 0));
    d[0][0] = 0;
    while(!que.empty()){
        P p = que.front();
        que.pop();
        int x = p.first, y = p.second;
        if(maze[x][y] == INF) return d[x][y];
        for(int i = 0; i < 4; i ++){
            int nx = x + dx[i], ny = y + dy[i];
            if(0 <= nx && 0 <= ny && d[nx][ny] == INF && d[x][y] + 1 < maze[nx][ny]){
                que.push(P(nx, ny));
                d[nx][ny] = d[x][y] + 1;
            }
        }
    }
    return -1;
}

void solve(){
    for(int i=0;i<MAX_N;i++)
    for(int j=0;j<MAX_N;j++)
    maze[i][j]=INF;
    for(int i = 0; i < M; i ++){
        maze[X[i]][Y[i]] = min(maze[X[i]][Y[i]], T[i]);
        for(int j = 0; j < 4; j ++){
            int nx = X[i] + dx[j], ny = Y[i] + dy[j];
            if(0 <= nx && 0 <= ny)
                maze[nx][ny] = min(maze[nx][ny], T[i]);
        }
    }
    for(int i=0;i<MAX_N;i++)
    for(int j=0;j<MAX_N;j++)
       d[i][j]=INF;
    int ans = bfs();
    printf("%d\n", ans);
}

int main(){
    scanf("%d", &M);
    for(int i = 0; i < M; i ++){
        scanf("%d %d %d", &X[i], &Y[i], &T[i]);
    }
    solve();
    return 0;
}
