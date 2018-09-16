#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int i,n;
    while(cin>>n){
        queue <int> q;
        priority_queue <int> pq;
        stack <int> s;
        bool f[3];
            for(int i=0;i<3;i++)
                f[i]=true;//对应三种类型

        for(i=1;i<=n;i++){
            int a,b;
            cin>>a>>b;
            if(a==1){    //入
                q.push(b);
                pq.push(b);
                s.push(b);
            }
            else{    //出
                //依次对比
                if(f[0] && !q.empty()){
                    int x = q.front();
                    q.pop();
                    if(x==b) f[0]=true;
                    else f[0]=false;  //这样做是为了应对第一次
                }
                else f[0]=false;
                if(f[1] && !pq.empty()){
                    int x = pq.top();
                    pq.pop();
                    if(x==b) f[1]=true;
                    else f[1]=false;
                }
                else f[1]=false;
                if(f[2] && !s.empty()){
                    int x = s.top();
                    s.pop();
                    if(x==b) f[2]=true;
                    else f[2]=false;
                }
                else f[2]=false;
            }
        }
        //查找有几个符合输出
        int num=0;
        for(i=0;i<3;i++)
            {if(f[i])
                num++;}
        if(num==0)
            cout<<"impossible"<<endl;
        else if(num==1){
            if(f[0])
                cout<<"queue"<<endl;
            else if(f[1])
                cout<<"priority queue"<<endl;
            else if(f[2])
                cout<<"stack"<<endl;
        }
        else
            cout<<"not sure"<<endl;
    }
    return 0;
}
