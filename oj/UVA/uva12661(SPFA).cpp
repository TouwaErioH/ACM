/*
solution:   ����������·�����⣬�����ڱߵ�Ȩֵ���������£���������ֻ�ǿ���Ȩֵ
                ���һ�Ҫ���ǵ���һ���ߵġ����š�ʱ���Ƿ�Ҫ����ǰ���еȴ�����ʱȨֵҪ����
                �ȴ���ʱ�䡣����dijkstra���ģ�忪ͷע��

note:   1.ע����Ҫ���Ƿ�Ӧ����·�ڵȴ����жϣ�����Ȩֵ���жϡ�
            2.ע����Ƿ��ܹ���һ��·��������You must enter a road when it��s open, and leave it before it��s closed again.��
            3.��Ȩֵ���жϴ��������¼��������һ�ǲ���ͨ������·��������ǰ��һ��·����ʱ��
            ̫������û��·�ڡ���������Ŀ�����������Դ�·������;�����ܹ�������·��������Ҫ������һ��·ʱ��·�ڵȴ���
            ���ǲ���Ҫ�ȴ��Ϳ���ֱ�ӽ�����һ·
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

struct Edge {   //����ṹ�������洢��
    int from, to, open, close, time;
};
vector<int> G[maxn];
vector<Edge> edges;

struct HeapNode {   //����ýṹ����Ϊ����Ϊ���ȶ����е�Ԫ������
    int dist, u;
    bool operator < (const HeapNode& rhs) const {
        return dist > rhs.dist; //��Ȼ������С�ѵıȽ���
    }
};

int dijkstra() {
    priority_queue<HeapNode> q;
    for(int i = 0; i <= n; i++)  dist[i] = INF;
    dist[s] = 0;
    memset(vis, 0, sizeof(vis));
    q.push((HeapNode) {0, s});  //��{0, s}  �� ��� �� ��һ��HeapNode����ѹ����У����е�dist��Ա��u��Աֵ�ֱ�Ϊ0,s

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
            if(time > open) continue;   //��������·�����ѵ�ʱ����ڹر�·����ʱ�䣬���Դ�·��ͨ��������Ŀ�и�֪��һ�����Ƿ����ߵ�����

            if(dist[from] % (open + close) + time <= open) {    //���õȴ�ֱ�ӽ����·��
                if(dist[to] > dist[from] + time) {  //ֱ�ӶԸñ߽����ɳڲ���
                    dist[to] = dist[from] + time;
                    q.push((HeapNode) {dist[to], to});
                }
            } else {    //��Ҫ�ڡ�����ǰ���ȴ�һ��
                int wt = dist[from] + time + open + close - dist[from] % (open + close);
                if(dist[to] > wt) {     //��open + close - dist[from] % (open + close)���ǵȴ���ʱ�䣬����wt��ͨ����Ҫ����ʱ��
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
        edges.clear();  //�ȶ�Ҫʹ�õ�vector�������г�ʼ��

        Edge tmp;   //��ʼ��������
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d%d%d", &tmp.from, &tmp.to, &tmp.open, &tmp.close, &tmp.time);
            edges.push_back(tmp);   int m = edges.size();
            G[tmp.from].push_back(m - 1);   //ע���¼���Ǳ���edges�����е��±꣬������Ϊ���ܹ����ʵ�Ȩֵ
        }
        int ans = dijkstra();   //����dijkstra���ش�
        printf("Case %d: %d\n", ++kase, ans);   //ע���ʽ
    }
    return 0;
}
