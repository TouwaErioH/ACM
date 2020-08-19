// 最小生成树 prim
#include<iostream>
#include<cstdio>

using namespace std;

const int N=101;

int mapp[N][N];
int t,num;
int i,j,k;

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>num;
        for(i=1;i<=num;++i)
            for(j=1;j<=num;++j)
                cin>>mapp[i][j];
        
        int sum=0,flag[N]={0};//flag[i]标识节点i是否已经被覆盖 
        flag[1]=1;

        for(k=1;k<num;++k)
        {
            int min=-1,min_weight;
            for(i=1;i<=num;++i)//选取下一个权值最小的节点
            {
                if(flag[i]==0&&(min==-1||mapp[1][i]<min))
                {
                    min=mapp[1][i];
                    min_weight=i;
                }
            }
            flag[min_weight]=1;
            for(i=1;i<=num;++i)
            {
                if(flag[i]==0&&mapp[1][i]>mapp[min_weight][i])
                {
                    mapp[1][i]=mapp[min_weight][i];
                }
            }
            sum+=mapp[1][min_weight];
        }
        cout<<sum<<endl;
    }
    return 0;
}