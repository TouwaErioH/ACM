---
title: 常见数据结构/算法模板
date: 2020-08-20
categories: acm
tags: acm
top: true
---

#0. to start with
remembering one trick is better than recording a hundred.

包含一些模板和例题

技巧,STL,函数,细节,参考资料（比如背包九讲)等见 https://www.cnblogs.com/lqerio/p/13484897.html

#1. DP Dynamic Programming

如果前面的结果可以被利用，就可以dp。
先写状态转移方程，边界条件，初始结束状态的设置。
如果数据计算量大可以预处理。
```
woj1023.
dp 状态转移方程: f[i]=min(f[i],f[j]+valuecluser[j+1][i])(i-j>=p)  //j+1...注意分界点 dp[0]=0.i in range p-1-N （编号为1-n）
//dp注意初始状态结束状态预处理。f[0]=0，f[i]初始为maxd
预处理：计算valuecluster[i][j]
```

## 1.1 Pack 背包

### 1.1.1 01背包

```
WOJ1005
const int maxn=10005;
int value[maxn];
int sizee[maxn];
int final[100005];
for(int i=0;i<=noah;i++) final[i]=0;  
    for(int i=0;i<n;i++)
        for(int j=noah;j>0;j--)   //倒序理解就是01背包只有一件，前i-1件已经判断完了，只判断这一件，在比较小的情况下放不影响在比较大的情况放
            if(j>=sizee[i])         //final可行因为如果小的能放大的也能放。
                final[j]=max(final[j],final[j-sizee[i]]+value[i]);
        cout<<final[noah]<<endl;
    }
```

## 1.2 剪枝 / 回溯

```
还是待更新！！！！
下面的不全

剪枝
1.最优化剪枝：如果当前已经找到的最优路径长度为L ,那么在继续搜索的过程中，总长度已经大于等于L的走法，就可以直接放弃，不用走到底了

2.可行性剪枝：如果当前到达城市的路费已大于k，或者等于k且没有到达终点，就可以直接放弃。

回溯

used[i] = 1;//设为用过 
            dfs(u + 1);//下一个数字 
            used[i] = 0;//回溯：回到没用过 
			
```

## 1.3 方格&&滚动数组&&优化时间 
见我的woj1012题解

#2. DFS

##2.1 recursive
```
PAT 1004
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<int>nodes[100];
int ans[105];
int level;
void dfs(int id,int depth){
    level=max(level,depth);
    int temp=id;
        if(nodes[temp].size()==0){
            ans[depth]++;
        }
        else{
            for(int i=0;i<nodes[temp].size();i++){
                dfs(nodes[temp][i],depth+1);
            }
        }
}

int main(){
    int n,m;
    cin>>n>>m;
    int father,num,son;
    for(int i=0;i<m;i++){
        cin>>father>>num;
        for(int j=0;j<num;j++){
            cin>>son;
            nodes[father].push_back(son); // at first i write push_back[]
        }
    }
    level=1;
    dfs(1,level);
    cout<<ans[1];
    for(int i=2;i<=level;i++) //at first i write push_back[] < but not <=
        cout<<' '<<ans[i];
        system("pause");
    return 0;
}
```
##2.2 stack
```
找到与最先出发点的所有邻接点，将他们入栈，
标记这些点已经访问过，后面和bfs的队列实现有点像。
UVA280

#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
int node_num,st,ed,stnodenum,stnode,vis[maxn];
 
void dfs(int stnode,vector<int> v[]){
    memset(vis,0,sizeof(vis));
    stack<int> s;
    vector<int> t;
    for(int i=0;i<v[stnode].size();i++){
        int temp=v[stnode][i];
        if(!vis[temp]){
            s.push(temp);
            vis[temp]=1;
        }
    }
    while(!s.empty()){
        int ans=s.top();
        s.pop();
        for(int i=0;i<v[ans].size();i++){
            int temp=v[ans][i];
            if(!vis[temp]){
                s.push(temp);
                vis[temp]=1;
            }
        }
    }
    for(int i=1;i<=node_num;i++){
        if(!vis[i])
        t.push_back(i);
    }
    cout<<t.size();
    for(int i=0;i<t.size();i++)
        cout<<" "<<t[i];
    cout<<endl;
}
 
int main(){
    while(scanf("%d",&node_num)!=EOF){
        if(node_num==0) break;
        vector<int> v[maxn];
        for(;;){
            scanf("%d",&st);
            if(!st)
                break;
            for(;;){
                scanf("%d",&ed);
                if(!ed)
                    break;
                v[st].push_back(ed);
            }
        }
        scanf("%d",&stnodenum);
        for(int i=0;i<stnodenum;i++){
            scanf("%d",&stnode);
            dfs(stnode,v);
        }
    }
    return 0;
```

#3. BFS

##3.1 QUEUE
```
PAT 1004
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<int>nodes[100];
int ans[105];
int depth[105];
int level;
void bfs(int id){
    queue<int>q;
    q.push(id);
    while(!q.empty()){
        int temp=q.front(); //at first i write "top()"
        q.pop();
        level=max(level,depth[temp]);
        if(nodes[temp].size()==0){
            ans[depth[temp]]++;
        }
        else{
            for(int i=0;i<nodes[temp].size();i++){
                depth[nodes[temp][i]]=depth[temp]+1;
                q.push(nodes[temp][i]);
            }
        }
        
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int father,num,son;
    for(int i=0;i<m;i++){
        cin>>father>>num;
        for(int j=0;j<num;j++){
            cin>>son;
            nodes[father].push_back(son); // at first i write push_back[]
        }
    }
    depth[1]=1;
    level=1;
    bfs(1);
    cout<<ans[1];
    for(int i=2;i<=level;i++) //at first i write push_back[] < but not <=
        cout<<' '<<ans[i];
        system("pause");
    return 0;
}
```

##3.2 recursion
```
void BFS(int st) {
	int len = G[st].size();
	for (int i = 0 ; i < len ; i ++ ) {
		que.push(G[st][i]);
	}
	if ( !que.empty() ) {
		int top = que.front() ; que.pop() ;
		printf("%d ",top) ;
		BFS(top) ;
	}
```

#4. topo 拓扑排序
//拓扑排序可以判断有向图有没有环。
//dfs判断图联通。

#5. math
##5.1 euler path /circuit
https://www.cnblogs.com/wkfvawl/p/9626163.html

DFS Fleury(佛罗莱)算法求解

##5.2 Huffman Coding 哈夫曼编码

#6. GRAPH 图
##6.1 Red Black Tree

##6.2 AVL 

##6.3 tree traversal 树的遍历
https://www.cnblogs.com/qjmnong/p/9135386.html
### Pre-order
#### recursive
void pre_order(TreeNode * Node)
{
    if(Node == NULL)
        return;
    printf("%d ", Node->data);
    pre_order(Node->left);
    pre_order(Node->right);
}
#### Iteration

```
class TreeNode {
	public int val;
	public TreeNode left, right;

	public TreeNode(int val) {
		this.val = val;
		this.left = this.right = null;
	}
}
```

先push(root)
node = pop()
loop:
    list.add( node.val )
    push( node.right )
    push( node.left )
    循环步骤直到栈空

```
public List<Integer> preorderTraversal(TreeNode root) {
		if (root == null) {
			return null;
		}
		List<Integer> list = new ArrayList<Integer>();

		Stack<TreeNode> s = new Stack<TreeNode>();
		s.push(root);

		while (!s.isEmpty()) {
			
			TreeNode node = s.pop();
			list.add(node.val);
			
			if (node.right != null) {
				s.push(node.right);
			}
			
			if (node.left != null) {
				s.push(node.left);
			}
		}
		
		return list;
	}
```


### Middle-order 
#### recursive
```
void middle_order(TreeNode *Node)//中序遍历递归算法
{
    if(Node == NULL)
        return;
    middle_order(Node->left);
    printf("%d ", Node->data);//在中间
    middle_order(Node->right);
}
```
#### Iteration
把root、以及root左孩子都压入栈中
loop:
    node = pop()
    list.add( node.val )
    root = node.right
    循环步骤直到栈为空且root为null
```
public static List<Integer> inorderTraversal(TreeNode root) {
		if (root == null) {
			return null;
		}
		List<Integer> list = new ArrayList<Integer>();

		Stack<TreeNode> s = new Stack<TreeNode>();

		do {
			while (root != null) {
				s.push(root);
				root = root.left;
			}
			if (!s.isEmpty()) {
				TreeNode node = s.pop();
				list.add(node.val);
				root = node.right;
			}
		} while (!s.isEmpty() || root != null);

		return list;
	}
```

### Post-order 
#### recursive
```
void post_order(TreeNode *Node)//后序遍历递归算法
{
    if(Node == NULL)
        return; 
    post_order(Node->left);
    post_order(Node->right);
    printf("%d ", Node->data);//在最后
}
```
#### Iteration
先push(root)
loop:
    node = pop()
    list.add( 0 , node.val )
    push( node.left )
    push( node.right )
    循环步骤3直到栈空
之后倒序遍历list
```
public static List<Integer> postorderTraversal(TreeNode root) {
		if (root == null) {
			return null;
		}
		List<Integer> list = new ArrayList<Integer>();

		Stack<TreeNode> s = new Stack<TreeNode>();
		
		s.push(root);
		
		while( !s.isEmpty() ) {
			TreeNode node = s.pop();
			if(node.left != null) {
				s.push(node.left);
			}
			
			if(node.right != null) {
				s.push(node.right);
			}
			
			list.add(0, node.val);
		}
		
		return list;
	}
```
##6.4 BST (binary search tree)
https://www.cnblogs.com/lqerio/p/11901828.html

##6.5 最短路
https://blog.csdn.net/strve/article/details/80957491
Floyed +Dijkstra + Bellman-Ford + SPFA （SPFA就是队列优化版的BF）。
///BF 适用于含有负边的图。如果有负边，返回false。Dijkstra算法无法判断含负权边的图的最短路.二者都适用于有向有环图。
//拓扑排序可以判断有向图有没有环。
//dfs判断图联通。

###6.5.1 dijkstra
PAT 1003 为例

#### 模板 Dijkstra+链式前向星+堆优化
https://www.cnblogs.com/zmin/p/7349100.html 

#### matrix O() 邻接矩阵版
```
#include<bits/stdc++.h>
using namespace std;
int graph[505][505];//图
int city[505],dis[505],pathNum[505],teamNum[505];//每个城市救护队的数量、到达每个城市的最短距离、到达每个城市的最短路径的数量、到达每个城市的救护队数量
bool visit[505];//每个城市是否被访问过
int N,M,C1,C2;
void Dijkstra(){
    while(!visit[C2]){//如果终点城市还没有被访问，继续循环
        int MIN=INT_MAX,v=-1;//找出目前距离最短的还没有被访问的城市
        for(int i=0;i<N;++i)
            if(!visit[i]&&MIN>dis[i]){
                MIN=dis[i];
                v=i;
            }
        visit[v]=true;//标记为已访问
        for(int i=0;i<N;++i)
            if(!visit[i]&&graph[v][i]!=0&&dis[v]+graph[v][i]<dis[i]){
                dis[i]=dis[v]+graph[v][i];//更新最短路径长度
                pathNum[i]=pathNum[v];//更新最短路径数量
                teamNum[i]=teamNum[v]+city[i];//更新城市的救护队数量
            }else if(graph[v][i]!=0&&dis[v]+graph[v][i]==dis[i]){
                pathNum[i]+=pathNum[v];//增加最短路径数量
                teamNum[i]=max(teamNum[i],teamNum[v]+city[i]);//找出能够召集最多的城市救护队数量
            }
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;++i)
        scanf("%d",&city[i]);
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b]=c;
        graph[b][a]=c;
    }
    fill(dis,dis+N,INT_MAX);//将最短路径均设置为最大值
    dis[C1]=0;//C1城市是起点，最短路径为0
    teamNum[C1]=city[C1];//C1城市是起点，最短路径数量为1
    pathNum[C1]=1;//C1城市是起点，能够召集的救护队数量为本城市的数量
    Dijkstra();
    printf("%d %d",pathNum[C2],teamNum[C2]);//输出
    return 0;
}
```
#### 邻接表版
```
#include<bits/stdc++.h>
using namespace std;
struct Road{
    int v;//道路尽头的城市编号
    int length;//道路长度
    Road(int vv=0,int l=0):v(vv),length(l){}
};
vector<vector<Road>>graph(505);//图
int city[505],dis[505],pathNum[505],teamNum[505];//每个城市救护队的数量、到达每个城市的最短距离、到达每个城市的最短路径的数量、到达每个城市的救护队数量
bool visit[505];//每个城市是否被访问过
int N,M,C1,C2;
void Dijkstra(){
    while(!visit[C2]){//如果终点城市还没有被访问，继续循环
        int MIN=INT_MAX,v=-1;//找出目前距离最短的还没有被访问的城市
        for(int i=0;i<N;++i)
            if(!visit[i]&&dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
        visit[v]=true;//标记为已访问
        for(Road r:graph[v]){
            if(!visit[r.v]&&dis[r.v]>dis[v]+r.length){
                dis[r.v]=dis[v]+r.length;//更新最短路径长度
                pathNum[r.v]=pathNum[v];//更新最短路径数量
                teamNum[r.v]=teamNum[v]+city[r.v];//更新城市的救护队数量
            }else if(dis[r.v]==dis[v]+r.length){
                pathNum[r.v]+=pathNum[v];//增加最短路径数量
                teamNum[r.v]=max(teamNum[r.v],teamNum[v]+city[r.v]);//找出能够召集最多的城市救护队数量
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;++i)
        scanf("%d",&city[i]);
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back(Road(b,c));
        graph[b].push_back(Road(a,c));
    }
    fill(dis,dis+N,INT_MAX);//将最短路径均设置为最大值
    dis[C1]=0;//C1城市是起点，最短路径为0
    pathNum[C1]=1;//C1城市是起点，最短路径数量为1
    teamNum[C1]=city[C1];//C1城市是起点，能够召集的救护队数量为本城市的数量
    Dijkstra();
    printf("%d %d",pathNum[C2],teamNum[C2]);//输出
    return 0;
}
```
#### priority_queue lrj版
设m edges,n vertexs
复杂度 mlog(n)
算法中 ** while(!Q.empty()){} ** 部分使得每个边都被遍历到,m。而优先队列插入复杂度为log(n).故整体mlog(n)
注意m可能大于n^2 最后复杂的>n^2.但不常见
```
PAT 1003

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include<vector>

using namespace std;
const int maxn = 505 + 5; //vertexs
const int INF = 99999999;

int city[505];
int pathnum[505],teamnum[505];

struct Edge
{
    int from,to,dist;
    Edge(int f=0,int t=0,int d=0):from(f),to(t),dist(d){}
};
struct HeapNode//优先队列节点
{
    int d,u;
    HeapNode(int _d=0,int _u=0):d(_d),u(_u){}
    bool operator<(const HeapNode &rhs)const
    {
        return d>rhs.d;
    }
};
struct Dijkstra  //边权为正 负权存在用Bellman-Ford 每两点间最短路floyd
{
    int n,m;               //点数和边数  O(mlog n)
    vector<Edge> edges;    //边列表
    vector<int> G[maxn];   //每个节点出发的边编号(编号从0开始)
    bool done[maxn];       //是否已永久标号
    int d[maxn];           //s到各个点的距离
    int p[maxn];           //最短路中的上一条边
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int dist)
    {
        edges.push_back(Edge(from,to,dist));
        m=edges.size();
        G[from].push_back(m-1);
        
                edges.push_back(Edge(to,from,dist)); //无向图，双向
        m=edges.size();
        G[to].push_back(m-1);
    }

    void dijkstra(int s)   //s start
    {
        priority_queue<HeapNode> Q;   //优先队列,d[i]越小越先出队
        for(int i=0;i<n;i++)d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push(HeapNode(0,s));
        while(!Q.empty()) //第一轮将s能到的点都压入队列,之后每次取d[i]最小的点先出(优先队列)
        {
            HeapNode x=Q.top();Q.pop();
            int u=x.u;                     //u 当前处理点编号
            if(done[u])continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++)
            {
                Edge &e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist; //d[u],出发点s到u的距离
                    p[e.to]=G[u][i];     //到达e.to点的边为G[u][i]
                    Q.push(HeapNode(d[e.to],e.to));
                        pathnum[e.to]=pathnum[e.from];
                        teamnum[e.to]=city[e.to]+teamnum[e.from];
                }
                else if(d[e.to]==d[u]+e.dist){
                         pathnum[e.to]+=pathnum[e.from];
                        teamnum[e.to]=max(city[e.to]+teamnum[e.from],teamnum[e.to]);
                }
            }
        }
    }
};

int main()
{
    Dijkstra dijk;
    int n,m,start,end;                 //n number of vertex m number of edges
    cin>>n>>m>>start>>end;
    for(int i=0;i<n;i++)
        cin>>city[i];
        dijk.init(n);
        int from,to,dist;
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d",&from,&to,&dist);
            dijk.AddEdge(from,to,dist);
        }
    pathnum[start]=1;
    teamnum[start]=city[start];
    dijk.dijkstra(start);
    cout<<pathnum[end]<<' '<<teamnum[end];
    
    return 0;
}

```


### 6.5.2 SPFA

#### woj1009
```
// woj1009

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


```

## 6.6 生成树

## 6.7 如何建图？

```
邻接矩阵  //数据范围很大，不能用邻接矩阵

邻接表

邻接表可以用 链表或者 vector 见 woj1006

vector<int>mapp;
for(int i=0;i<n;i++)
            mapp[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d", &x, &y);  mapp[x].push_back(y);  mapp[y].push_back(x);
        }


紫书模板建图 见我的题解 woj1009


一般的用vector[i]表示i所连边 见我的题解 woj1024

```

#7. Sort
https://www.cnblogs.com/lqerio/p/13484897.html


#8. greedy 贪心
https://www.cnblogs.com/lqerio/p/11749926.html

#9. 字符串 string

##9.1 KMP

##9.2 AC 自动机

##9.3 字典序 Dictionary order
https://www.cnblogs.com/lqerio/p/11785894.html

sort，strcmp,string
```
woj1013
字典序全排列生成：https://www.cnblogs.com/lqerio/p/12079873.html

比较可以用sort（qsort不推荐）
bool cmp(char*a,char*b){
    return strcmp(a,b);
}

bool cmp1(string a,string b){
    return a<b;
}
vector<string>ans;
sort(ans.begin(),ans.end(),cmp1);
```

##9.4 leetcode5 Manacher法 最长回文字符串
https://www.cnblogs.com/lqerio/p/11723652.html


#10. 网络流
见woj1008.

#11. kth biggest/smallest
https://www.cnblogs.com/lqerio/p/9757284.html



#12. others

##12.1 make an structure of O(1)  search，insert，delete
leetcode381

##12.2 GCD
```
    int gcd(int a,int b)
    {
       // return (b==0)?gcd(b,a%b):a
         if(b==0)
              return a;
         else
              return gcd(b,a%b);
    }
```

##12.3 Prime
```
bool isPrime(int n) {

	if (n < 2)
		return false;
   int m=sqrt(n+0.5);
	for (int i = 2; i <= m; i++) {

		if (n % i == 0)
			return false;
	}

	return true;
}

void euler_sieve(int n)  //线性筛
{
    totPrimes = 0;
    memset(flag, 0, sizeof(flag));

    for (int i = 2; i <= n; i++) {
        if (!flag[i])
            primes[totPrimes++] = i;
        for (int j = 0; i * primes[j] <= n; j++) {
            flag[i*primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void eratosthenes_sieve(int n)
{
    totPrimes = 0;
    memset(flag, 0, sizeof(flag));

    int sqrtn = sqrt(n + 0.5);
    for (int i = 2; i <= sqrtn; i++) {
        if (!flag[i]) {
            primes[totPrimes++] = i;
            for (int j = i * i; j <= n; j += i) {
                flag[j] = true;
            }
        }
    }
    for (int i = sqrtn + 1; i <= n; i++) {
        if (!flag[i])
            primes[++totPrimes] = i;
    }
}
```

##12.4 binary_search
```
int binarysearch(int x)
{
    int l=0,r=n*n;
    while(r-l>=1)
    {
        int i=(r+l)/2;
        if(num[i]==x) return 1;
        else if(num[i]<x) l=i+1;
        else r=i;
    }
    return 0;
}
```

##12.5 pow
```
ll pow(ll a,ll n) //a^n
{
    ll result=1,flag=a;
    while(n!=0)
    {
        if(n&1)
            result=result*flag;
        flag=flag*flag;
        n=n>>1;
    }
    return result;
}

ll pow(ll a,ll n,ll b) //a^n %b  to avoid Integer overflow
{
    ll result=1;
    a=a%b;
    while(n>0)
    {
        if(n%2==1)
            result=result*a%b;
        n=n/2;
        a=a*a%b;
    }
    return result;
}
```

##12.6 floating numbers
uva11809 
https://blog.csdn.net/crazysillynerd/article/details/43339157

```

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
 
using namespace std;
 
int main() {
    double M[20][40];
    long long E[20][40];
 
    // 打表
    for(int i = 0; i <= 9; ++i) for(int j = 1; j <= 30; ++j) {
        double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1;
        double t = log10(m) + e * log10(2);
        E[i][j] = t, M[i][j] = pow(10, t - E[i][j]);
    }
 
    // 输入并输出结果
    string in;
    while(cin >> in && in != "0e0") {
        // 处理输入
        for(string::iterator i = in.begin(); i != in.end(); ++i) if(*i == 'e') *i = ' ';
        istringstream ss(in);
        double A; int B;
        ss >> A >> B;
        while(A < 1) A *= 10, B -= 1;
        // 在打好的表中寻找答案
        for(int i = 0; i <= 9; ++i) for(int j = 1; j <= 30; ++j) {
            if(B == E[i][j] && (fabs(A - M[i][j]) < 1e-4 || fabs(A / 10 - M[i][j]) < 1e-4)) {
                cout << i << ' ' << j << endl;
                break;
            }
        }
    }
}
```

##12.7 high accuracy
https://www.cnblogs.com/ECJTUACM-873284962/p/6509429.html
uva 1828 fibonacci
https://www.xuebuyuan.com/1888279.html
```
#include <iostream>
#include <string.h>

using namespace std;

int f[5010][1010];       //第1个5010用来存5010个斐波那契数（测试可知第5000项已超过了1000位），第2个1010表示给每个斐波那契数开1010位

int main()
{
    int i, j;

    memset(f, 0, sizeof(f));

    f[1][0] = 1;        //给第1个斐波那契数置数
    f[2][0] = 1;        //给第2个斐波那契数置数

    for(i = 3; i < 5010; i++)      //从第3项开始，用前2项相加
    {
        int C = 0;      //C表示进位，开始设为0
        for(j = 0; j < 1001; j++)
        {
            f[i][j] = (f[i-2][j] + f[i-1][j] + C) % 10;     //%10后就是这一位该有的数字
            C = (f[i-2][j] + f[i-1][j] + C) / 10;       //相加产生的进位
        }

    }

    int a;
    while(cin>>a)
    {
        for(j = 1001; j >= 0; j--)      //寻找最高位
            if(f[a][j] != 0)
                break;
        for(; j >= 0; j--)
            cout<<f[a][j];
        cout<<endl;
    }
    return 0;
}
```
##12.8 big number //JAVA and PYTHON are highly recommended
https://www.cnblogs.com/lqerio/p/11117608.html

##12.9 c++ stl
https://www.cnblogs.com/lqerio/p/13484897.html
https://www.cnblogs.com/lqerio/p/11117601.html

##12.10 滑动窗口 Sliding window
https://www.cnblogs.com/lqerio/p/11708680.html
https://www.cnblogs.com/lqerio/p/9741044.html

##12.11 双指针...三指针... two-pointer
https://www.cnblogs.com/lqerio/p/11755868.html

