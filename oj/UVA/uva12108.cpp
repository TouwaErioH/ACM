#include<stdio.h>
struct student{
int a,b,c,all,state;
}stu[15];
#define maxt 300

int main()
{
    int n,T=0;
    while(scanf("%d",&n)==1&&n!=0)
    {
        T++;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
            stu[i].all=stu[i].a+stu[i].b;
            stu[i].state=(stu[i].a<stu[i].c)?1:0;
        }
        int t=1, flag=0;
        while(t<maxt)
        {
            int sleep=0,awake=0;    //位置！

            for(int i=1;i<=n;i++)
            {
            if(stu[i].state)
                sleep++;
                else awake++;
            }

            if(awake==n) {flag=1;break;}
            for(int i=1;i<=n;i++)
                {
            if(stu[i].c==stu[i].a)  //不能直接sleep++，会影响状态，所以添加了state
            {
                if(sleep>awake)
                {
                    stu[i].state=1;stu[i].c++;
                }
                else
                {
                    stu[i].state = 0; stu[i].c = 1;
                }
            }
               else if(stu[i].c==stu[i].all)
                {stu[i].c=1;stu[i].state=0;
                }
                else stu[i].c++;
              }
        t++;

    }
    if(flag==1) printf("Case %d: %d\n",T,t);
    else printf("Case %d: -1\n", T);
}
 return 0;
}
