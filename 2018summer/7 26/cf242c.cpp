#include<iostream>   //bfs
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
    int x0,y0,x1,y1,n;
    queue<pair<int,int> >q;//����һ��pair�Ķ���
    map<pair<int,int>,int>m;//��pair���͵�ӳ���һ����
int main(){
    int r,a,b;
    int i,j;
    int x,y,nx,ny;
    int next[8][2]={ {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
    while(scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&n)!=EOF){
        while(!q.empty()) q.pop();
        m.clear();
        while(n--){
            scanf("%d%d%d",&r,&a,&b);//r�е�a~b���ǿ����ߵ�·��
            for(i=a;i<=b;i++){
                m[make_pair(r,i)]=-1;//�ѿ����ߵĵ�ӳ���-1
            }
        }
            m[make_pair(x0,y0)]=0;//���Ĳ���Ϊ0
            q.push(make_pair(x0,y0));//��������
            while(!q.empty()){
                x=q.front().first;//�������һ�����ݵĵ�һ����
                y=q.front().second;//�������һ�����ݵĵڶ�����

                q.pop();
                for(i=0;i<8;i++){
                nx=x+next[i][0];
                ny=y+next[i][1];
                if(m[make_pair(nx,ny)]<0){//�ж�������Ƿ�����ߵ�
                    m[make_pair(nx,ny)]=m[make_pair(x,y)]+1;//����+1
                    q.push(make_pair(nx,ny));
                }
            }
            }
        printf("%d\n",m[make_pair(x1,y1)]);//���������߲����ͻ���-1����Ҳ��Ϊʲôӳ���-1��ԭ�򣩣��ߵ���ľ������·
    }
    return 0;   //����һ�¾�֪�����Ǵ����������ɢ��ÿ��������ִ������㵽�������̲������յ㲻һ������ߵ�����һ�������·
}
