#include <stdio.h>
#include <string.h>
#define maxn 105
int less(char *s,int p,int q)
{
   int i,n;
   n=strlen(s);
   for(i=0;i<n;i++)
   {
      if(s[(p+i)%n]!=s[(q+i)%n])
      return s[(p+i)%n]<s[(q+i)%n];
   }
   return 0;
}
int main()
{
   int T ;
   char s[maxn];
   scanf("%d",&T);
   while(T--)
   {
      scanf("%s",s);
      int ans=0;
      int n=strlen(s);
      int i;
      for(i=0;i<n;i++)
      {
         if(less(s,i,ans)) ans=i;
      }
      for(i=0;i<n;i++)
         putchar(s[(ans+i)%n]);
         putchar('\n');
   }
   return 0;
}
