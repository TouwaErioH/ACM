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
               tnext[i]=tnext[cur];//next��i����ʾs��i���ұߵ��ַ���s�е��±ꣻ���һ��Ϊ0
               tnext[cur]=i;
               if(cur==last)
                last=i;     //last�������home֮ǰ��last��Ҳ��Ҫ����
               cur=i;
           }
       }
        for(int i=tnext[0];i!=0;i=tnext[i])
               printf("%c",s[i]);
               printf("\n");
   }

    return 0;
}
