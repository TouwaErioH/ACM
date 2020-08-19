//数据范围很大，不能用邻接矩阵
//没有边权，BFS就行，不用最短路

// 建图用链表或者vector
// BFS用QUEUE DFS用栈
#include <iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
 
const int  maxn= 200005;  //我傻了  写成20000+5，然后SEGMENTFAULT 

vector<int> mapp[maxn];
bool visited[maxn];

struct Node {
    int a, len;  //s 到 a的距离 len
    Node(int a, int len) : a(a), len(len) {}
};
 
queue<Node> que;

void clearque(queue<Node>& q){
    queue<Node> empty;
    swap(empty, q);
}

int bfs(int s, int e)
{
    for(int i=0;i<maxn;i++)
        visited[i]=false;
    visited[s] = true;
    clearque(que);
    que.push(Node(s, 0));
    while(!que.empty()) {
        Node tmp = que.front();
        que.pop();
        if(tmp.a == e) 
            return tmp.len==0?0:tmp.len-1;
        // if(!mapp[tmp.a].empty()) 
        for(vector<int>::iterator iter = mapp[tmp.a].begin(); iter != mapp[tmp.a].end(); iter++) {
            if(!visited[*iter]) {
                visited[*iter] = true;
                que.push(Node(*iter, tmp.len + 1));
            }
        }
    }
    return -1;
}
 
int main()
{
    int n=0,m=0,q=0,x=0,y=0;
    while(scanf("%d%d", &n, &m)==2) {
        for(int i=0;i<n;i++)
            mapp[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d", &x, &y);  mapp[x].push_back(y);  mapp[y].push_back(x);
        }
        scanf("%d", &q);
        for(int i=0;i<q;i++){
            scanf("%d%d", &x, &y);
            cout<<bfs(x,y)<<endl;
        }
    }
    return 0;
}
