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

        map<int , int> team;//ӳ�������Ǳ��x��Ӧ���Ķ���i
        for(int i = 0; i < t; i++) {
            int n,x;
            scanf("%d", &n);
            while(n--) { scanf("%d", &x); team[x] = i;}
        }

        queue<int> q, q2[maxt];
        //���������Ǳ���ĺ���
        //q��ŵ��Ƕ��飬q2��ŵ��ǰ��������е����еĶ����Լ������µı��
        //��q����Ŷ�������У���{3,1,2}
        //q2����ŶӶ��У���{103,101,102},{201},{301,303}
        for(;;) {
        int x;
        char cmd[10];
        scanf("%s", cmd);
        if(cmd[0] == 'S') break;//����STOPֹͣ
        else if(cmd[0] == 'D'){
            int t = q.front();//�ñ���t��ʾ�Ŷ�������еĶ���
            printf("%d\n",q2[t].front()); q2[t].pop();//���������׶���ĵ�һ���ˣ�Ȼ��Ѹ��˳���
            if(q2[t].empty()) q.pop();//����ö���������������ֻ��һ���ˣ���q�Ķ��׳��ӣ����ö������
        }else if(cmd[0] == 'E'){
            scanf("%d", &x);
            int t = team[x];//ͨ��map�ҳ�x�Ķ������
            if(q2[t].empty()) q.push(t);//����öӻ�û�������ڶ��У���ö��в����β
            q2[t].push(x);//�Ѹö�����˲��뵽q2�ĸö���
            }
        }
        printf("\n");
    }
    return 0;
}
