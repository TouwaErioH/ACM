#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct t{
int x,y;
}k[6];
bool cmp(struct t a,struct t b)
{
    if(a.x!=b.x) return a.x>b.x;
    else return a.y>b.y;
}

int main()
{
    int a=0,b=0,t=0;
    while(scanf("%d%d",&a,&b)==2)
        {

    if(a<b)
    {t=a;a=b;b=t;}
    k[0].x=a;k[0].y=b;
    for(int i=1;i<6;i++)
   {
        int a=0,b=0,t=0;
   scanf("%d%d",&a,&b);
   if(a<b)
    {t=a;a=b;b=t;}
    k[i].x=a;k[i].y=b;
   }
   sort(k,k+6,cmp);
   int flag=1;
   if((k[0].x==k[1].x&&k[0].y==k[1].y&&k[2].x==k[3].x&&k[2].y==k[3].y&&k[4].x==k[5].x&&k[4].y==k[5].y&&k[0].x==k[2].x&&k[0].y==k[4].x&&k[4].y==k[2].y)==0)
    flag=0;
    printf("%s\n", flag? "POSSIBLE" : "IMPOSSIBLE");
    memset(k,0,sizeof(k));
    }
   return 0;
}
