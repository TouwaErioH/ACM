//输入n m n cities m条边
//格式 u v pguard sguard cost letter 
//while u and v represents the edge ,pguard and sguard represents power and speed of the guard,
// cost represents the cost of the road and letter represents the letter of the elixir the God placed.
//0 1 10 10 10 L
//The last line contains plovers slovers.plovers要大于路上守卫的guard,slovers要大于守卫的speed
// n 1-100 m 1-4000
//There'll be at least one path to go from Jerusalem to The Garden of Eden.You can assume no two paths have the same lentgh .

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
#define INF 0x3f3f3f3f


char word[4005];
int plovers,slovers;
int n, m,edgenum;
const int maxn=105;  //const    点的数

struct Edge {
int from, to, power,speed,dist;
char word;
Edge(int u, int v,int p,int s, int d,char word):from(u),to(v),power(p),speed(s),dist(d),word(word){}
};

vector<Edge> edges;
vector<int> G[maxn];
bool inq[maxn]; //是否在队列里
int d[maxn]; //s到各个点的距离
int p[maxn]; //最短路中的上一条弧
int cnt[maxn]; //入队次数 次数大于n则说明有负环

void init(int n) {
edgenum=0;
for(int i = 0; i < n; i++) G[i].clear();
edges.clear();
}

void AddEdge(int from, int to, int power,int speed,int dist,char word) {
edges.push_back(Edge(from, to, power,speed,dist,word));
edgenum = edges.size();           //错误，一开始写成m，而m又是全局变量导致下面data()的循环除了问题
G[from].push_back(edgenum-1);  //边的标号
}

//拓扑排序可以判断有向图有没有环
//dfs判断图联通

bool bellman_ford(int s) {  ///BF 适用于含有负边的图。如果有负边，返回false。Dijkstra算法无法判断含负权边的图的最短路.二者都适用于有向有环图
    queue<int> Q;
    memset(inq, 0, sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    inq[s] = true;
    p[s]=-1;     //加了一条
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = false;
        for(int i = 0; i < G[u].size(); i++) {
            Edge& e = edges[G[u][i]];
                if(d[u] < INF && d[e.to] > d[u] + e.dist&&plovers>e.power&&slovers>e.speed) {    //模板，+条件
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    if(!inq[e.to]) { Q.push(e.to); inq[e.to] = true; if(++cnt[e.to] > n) return false;}
                }
        }
    }
    vector<char>ans;  //也可以写一个函数递归,没必要
    int tmp=p[n-1];
    while(tmp!=-1){
        ans.push_back(edges[tmp].word);
        tmp=p[edges[tmp].from];
    }
    for(int i=ans.size()-1;i>-1;i--)
        cout<<ans[i];
    cout<<endl;
    return true;
}


void data(){
    init(n);
    int from,to,power,speed,dist,tmp;
    char word;
    for(int i=0;i<m;i++){
        /*  这样写有问题。读了空格
           scanf("%d%d%d%d%d",&from,&to,&power,&speed,&dist);
           scanf("%c",&word);
           */
          /*
          scanf("%d%d%d%d%d",&from,&to,&power,&speed,&dist);
           getchar();scanf("%c",&word);getchar();*/     //处理最后一个字符前的空格这样可以，但是麻烦
           scanf("%d %d %d %d %d %c",&from,&to,&power,&speed,&dist,&word);  //注意%c不是%s 。也可以fstream
           AddEdge(from,to,power,speed,dist,word);
           }
    cin>>plovers>>slovers;
    bellman_ford(0);
}

int main(){

    while(scanf("%d%d",&n,&m)==2){
        data();
        getchar();  //输入有空行
    }
    return 0;
}

