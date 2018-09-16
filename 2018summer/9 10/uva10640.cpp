#include<bits/stdc++.h>
using namespace std;
    int a,b;
    double cal(int N,double A){
    return ((double)a/b)*(3-2/(A+2)-2/(N-1-A+1));
    }
int main()
{
    int T,kase=0;
    cin>>T;

    while(T--){
        scanf("%d%d",&a,&b);
    if(a*3<=b)
    {
        printf("Case %d: -1\n",++kase);
        continue;
    }
    if(a>=b)
    {
        printf("Case %d: 1\n",++kase);
        continue;
    }
    else{
        int N=ceil((double)(3*b-a)/(3*a-b));
        if(!(N&1))
           N++;
        if(N>1)
        {
            double A=(N-1)/2-1;

cout<< cal(N,A)<<endl;

int x=floor(cal(N,A));
            if((x-1)>=0)
            {cout<<"00x00"<<endl;
                printf("Case %d: %d\n",++kase,N-1);}
        else
             printf("Case %d: %d\n",++kase,N);
        }
        else
            printf("Case %d: %d\n",++kase,N);
    }
    }
    return 0;
}


/*3 4   2
4 5 2
4 7 4
4 9 8
5 6 2
5 9 4*/
