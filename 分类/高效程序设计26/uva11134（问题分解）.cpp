#include<cstdio>
#include<set>
#include<algorithm>
const int N= 5010;
using namespace std;

struct mp
{
   int l ,r ,id;
};
int AnsX[N] ,AnsY[N];
mp X[N] ,Y[N];
set<int>set1 ,set2;
int x;

bool cmp(mp a ,mp b)
{
   return a.r < b.r;
}

void solve(int n)
{
int x1,x2,y1,y2;
set1.clear() ,set2.clear();
      for(int i = 1 ;i <= n ;i ++)
      {
         scanf("%d %d %d %d" ,&x1 ,&y1 ,&x2 ,&y2);
         X[i].l = x1 ,X[i].r = x2;
         Y[i].l = y1 ,Y[i].r = y2;
         X[i].id = Y[i].id = i;
         set1.insert(i);
         set2.insert(i);
      }
      set1.insert(N);
      set2.insert(N);
      sort(X + 1 ,X + n + 1 ,cmp);
      sort(Y + 1 ,Y + n + 1 ,cmp);
      int flag = 0;
      for(int i = 1 ;i <= n && !flag ;i ++)
      {
         int tmpx = *set1.lower_bound(X[i].l);
         if(tmpx > X[i].r) flag = 1;
         AnsX[X[i].id] = tmpx;
         set1.erase(tmpx);
         int tmpy = *set2.lower_bound(Y[i].l);
         if(tmpy > Y[i].r) flag = 1;
         AnsY[Y[i].id] = tmpy;
         set2.erase(tmpy);
      }
      if(flag)
      {
         puts("IMPOSSIBLE");
       return ;
      }
      for(int i = 1 ;i <= n ;i ++)
      printf("%d %d\n" ,AnsX[i] ,AnsY[i]);
}

int main ()
{
   while(scanf("%d" ,&x)==1 && x)
  solve(x);
   return 0;
}
