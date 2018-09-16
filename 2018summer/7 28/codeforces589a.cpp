#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
map<string,int>mp;
int id = 0;
int a[maxn];
int vis[maxn];
char s[maxn][105];
char s2[maxn][105];
char code[105];
vector<string>v[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i){
        scanf("%s",s2[i]);
        strcpy(s[i],s2[i]);
        for (int j = 0; s[i][j] != 0; ++j)s[i][j] = tolower(s[i][j]);
    }

    for (int i = 0; i < n; ++i){
        int pos = 0;
        for (;s[i][pos]!='@';++pos);
        strcpy(code,s[i]);

        //后缀百度的另行处理，code要重新编写
        if (strcmp(s[i]+pos+1,"bmail.com") == 0){
            int pls = -1;
            for (int j = 0; j < pos; ++j){
                if (s[i][j] == '+'){
                    pls = j;
                    break;
                }
            }
            int cnt = 0;
            for (int j = 0; j < (pls == -1 ? pos : pls); ++j){
                if (s[i][j] == '.')continue;
                code[cnt++] = s[i][j];
            }
            code[cnt] = 0;
        }


        if (!mp.count(code)){
            mp[code] = id;
            v[id].push_back(s2[i]);
            id++;
        }
        else{
            v[mp[code]].push_back(s2[i]);
        }
    }

    printf("%d\n",id);
    for (int i = 0; i < id; ++i){
        int len = v[i].size();
        printf("%d",len);
        for (int j = 0; j < len ; ++j)printf(" %s",v[i][j].c_str());
        printf("\n");
    }
    return 0;
}
