/*
solution:   本题就是最短路径问题，但是在边的权值上做了文章，并不单单只是考虑权值
                而且还要考虑到达一条边的“阀门”时，是否要在门前进行等待，此时权值要加上
                等待的时间。关于dijkstra详见模板开头注释

note:   1.注意需要对是否应该在路口等待做判断，即对权值做判断。
            2.注意对是否能够走一条路的条件“You must enter a road when it’s open, and leave it before it’s closed again.”
            3.对权值的判断此题有如下集中情况。一是不能通过这条路，即走完前面一条路所花时间
            太长，还没到路口。不符合题目中条件，所以此路不能走;二是能够走这条路，但是需要在走下一段路时在路口等待。
            三是不需要等待就可以直接进入下一路
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = 300 + 5;
const int maxm = 50000 + 5;
const int INF = 99999999;
int n, m, s, t, dist[maxn], vis[maxn];

struct Edge {   //定义结构体用来存储边
    int from, to, open, close, time;
};
vector<int> G[maxn];
vector<Edge> edges;

struct HeapNode {   //定义该结构体是为了作为优先队列中的元素类型
    int dist, u;
    bool operator < (const HeapNode& rhs) const {
        return dist > rhs.dist; //仍然定义最小堆的比较器
    }
};

int dijkstra() {
    priority_queue<HeapNode> q;
    for(int i = 0; i <= n; i++)  dist[i] = INF;
    dist[s] = 0;
    memset(vis, 0, sizeof(vis));
    q.push((HeapNode) {0, s});  //将{0, s}  “ 打包 ” 成一个HeapNode类型压入队列，其中的dist成员和u成员值分别为0,s

    while(!q.empty()) {
        HeapNode x = q.top();   q.pop();
        int u = x.u;
        if(vis[u])  continue;
        vis[u] = 1;

        for(int i = 0; i < G[u].size(); i++) {
            Edge& e = edges[G[u][i]];
            int time = e.time;
            int open = e.open;
            int close = e.close;
            int from = e.from;  int to = e.to;
            if(time > open) continue;   //行走这条路所花费的时间大于关闭路径的时间，所以此路不通。这是题目中告知的一条边是否能走的条件

            if(dist[from] % (open + close) + time <= open) {    //不用等待直接进入该路径
                if(dist[to] > dist[from] + time) {  //直接对该边进行松弛操作
                    dist[to] = dist[from] + time;
                    q.push((HeapNode) {dist[to], to});
                }
            } else {    //需要在“阀门前”等待一会
                int wt = dist[from] + time + open + close - dist[from] % (open + close);
                if(dist[to] > wt) {     //“open + close - dist[from] % (open + close)”是等待的时间，所以wt是通过需要的总时间
                    dist[to] = wt;
                    q.push((HeapNode) {dist[to], to});
                }
            }
        }
    }
    return dist[t];
}


int main()
{
    int kase = 0;
    while(scanf("%d%d%d%d", &n, &m, &s, &t) == 4) {
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear();  //先对要使用的vector容器进行初始化

        Edge tmp;   //开始读入数据
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d%d%d", &tmp.from, &tmp.to, &tmp.open, &tmp.close, &tmp.time);
            edges.push_back(tmp);   int m = edges.size();
            G[tmp.from].push_back(m - 1);   //注意记录的是边在edges容器中的下标，这样是为了能够访问到权值
        }
        int ans = dijkstra();   //调用dijkstra返回答案
        printf("Case %d: %d\n", ++kase, ans);   //注意格式
    }
    return 0;
}
