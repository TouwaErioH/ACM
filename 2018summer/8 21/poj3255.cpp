#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=5005;
const int inf=1e9;
int N,R;
struct edge
{
    int to,cost;
};
typedef pair<int ,int> P ;///first �Ǵ�1��second�����· second ��·�ڱ��
vector<edge>G[maxn];///�ڽӱ�
int dist[maxn];///���·
int dist2[maxn];///�ζ�·
void solve()
{
    priority_queue<P ,vector<P>,greater<P> >que;
    fill(dist,dist+N,inf);
    fill(dist2,dist2+N,inf);
    dist[0]=0;
    //dist2[0]=0;
    que.push(P(0,0));
    while(!que.empty())
    {
        P p=que.top();///���ȶ��� ����.top
        que.pop();
        int v=p.second ,d=p.first;
        if(dist2[v]<d)continue;
        for(int i=0; i<G[v].size(); i++)
        {
            edge e=G[v][i];
            int d2=d+e.cost;
            if(dist[e.to]>d2)
            {
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }
            if(dist2[e.to]>d2&&dist[e.to]<d2)
            {
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    printf("%d\n",dist2[N-1]);
}
int main()
{
    int from;
    while(cin>>N>>R)
    {
        edge now;
        for(int i=0;i<R;i++)
        {
            cin>>from>>now.to>>now.cost;
            from--;
            now.to--;///��Ŵ�  0-N-1����
            G[from].push_back(now);
            swap(now.to,from);
            G[from].push_back(now);
        }
        solve();
    }
    return 0;
}
