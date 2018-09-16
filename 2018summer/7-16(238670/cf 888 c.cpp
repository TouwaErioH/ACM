#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
char s[maxn];

int main()
{
    int temp[30];
    int dis[30]={0};//初始化判断，第一次就忘了
    scanf("%s",s);
    memset(temp,-1,sizeof(temp));
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        int letter=s[i]-'a';
        dis[letter]=max(dis[letter],i-temp[letter]);
        temp[letter]=i;
    }
    for(int i=0; i<26; i++)
        dis[i]=max(dis[i],len-temp[i]);//易错之处
    int ans=len;
    for(int i=0; i<26; i++)
    {
        if(dis[i]!=0)//忘了判断
    ans=min(ans,dis[i]);
    }
    printf("%d\n",ans);
    return 0;
}
