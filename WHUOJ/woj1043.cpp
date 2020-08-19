//数据弱,暴力;  正解：类似后缀数组，先把所有字符串排序，然后每相邻两个串lcp，得lcp数组，每个查询在对应的lcp区间取最小值，线段树rmq
/*
给几个名字和对应id
然后几个查询，查询内容为给定组的最长公共前缀的长度之和
*/

#include<map>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int a=6005,b=1005;
int ans,i,j;
char IDS[a][b];

int main(){
    int n,m,q;
    string temp;
    int tp;
    cin>>n;
    while(n--){
        cin>>tp;
        scanf("%s",IDS[tp]);
    }
    cin>>m;
    while(m--){
        cin>>q;
        ans=0;
        while(q--){
        cin>>i>>j;
        int len1=strlen(IDS[i]);
        int len2=strlen(IDS[j]);
        int minn=len1>len2?len1:len2;
        int k;
        for(k=0;k<minn;k++){
				if(IDS[i][k]!=IDS[j][k])
				break;
        }
        ans+=k;
        }
        cout<<ans<<endl;
    }
    return 0;
}