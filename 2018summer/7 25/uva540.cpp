#include<cstdio>
#include<queue>
#include<map>
using namespace std;
const int maxt = 1000 + 10;
int main()
{
    int t, kase = 0;
    while(scanf("%d", &t) == 1 && t) {
        printf("Scenario #%d\n", ++kase);

        map<int , int> team;//映射作用是编号x对应它的队伍i
        for(int i = 0; i < t; i++) {
            int n,x;
            scanf("%d", &n);
            while(n--) { scanf("%d", &x); team[x] = i;}
        }

        queue<int> q, q2[maxt];
        //两个队列是本题的核心
        //q存放的是队伍，q2存放的是按增序排列的所有的队伍以及队伍下的编号
        //即q存放团队整体队列，例{3,1,2}
        //q2存放团队队列，例{103,101,102},{201},{301,303}
        for(;;) {
        int x;
        char cmd[10];
        scanf("%s", cmd);
        if(cmd[0] == 'S') break;//遇到STOP停止
        else if(cmd[0] == 'D'){
            int t = q.front();//用变量t表示团队整体队列的队首
            printf("%d\n",q2[t].front()); q2[t].pop();//输出这个队首队伍的第一个人，然后把该人出队
            if(q2[t].empty()) q.pop();//如果该队伍在整个队列中只有一个人，则q的队首出队，即该队伍出队
        }else if(cmd[0] == 'E'){
            scanf("%d", &x);
            int t = team[x];//通过map找出x的队列序号
            if(q2[t].empty()) q.push(t);//如果该队还没有人排在队中，则该队列插入队尾
            q2[t].push(x);//把该队伍的人插入到q2的该队中
            }
        }
        printf("\n");
    }
    return 0;
}
