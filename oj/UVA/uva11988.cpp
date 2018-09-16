#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 100005
int last,cur,tnext[maxn];
char s[maxn];

int main()
{
   while (scanf("%s",s+1)==1)
   {
       int n=strlen(s+1);
       last=cur=0;
       tnext[0]=0;
       for(int i=1;i<=n;i++)
       {
           char ch=s[i];
           if(ch=='[')
            cur=0;
           else if (ch==']')
           cur=last;
           else
           {
               tnext[i]=tnext[cur];//next【i】表示s【i】右边的字符在s中的下标；最后一个为0
               tnext[cur]=i;
               if(cur==last)
                last=i;     //last保存的是home之前的last，也需要更新
               cur=i;
           }
       }
        for(int i=tnext[0];i!=0;i=tnext[i])
               printf("%c",s[i]);
               printf("\n");
   }

    return 0;
}
