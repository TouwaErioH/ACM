#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1010;

char str[MAXN];
int d[MAXN];

bool isPalind(int l, int r){
    while(l<r){
        if(str[l] != str[r]) return false;
        ++l; --r;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str+1);
        int len = strlen(str+1);
        memset(d, 0, sizeof(d));
        for(int i=1; i<=len; i++){
            d[i] = i+1;
            for(int j=1; j<=i; ++j)if(isPalind(j, i)){
                d[i] = min(d[i], d[j-1]+1);
            }
        }
        printf("%d\n", d[len]);
    }
    return 0;
}
