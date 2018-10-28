#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int f[110][110], g[110][110];
int p[35];

int main(){

    while(~scanf("%d%d", &n, &m) && n+m){

        for(int i=1; i<=m; ++i)
            scanf("%d", &p[i]);

        memset(f, 0, sizeof(f));

        for(int i=1; i<=m; ++i){
            f[i-1][0] = INF;
            for(int j=1; j<=n; ++j){
                f[i][j] = f[i-1][j];
                for(int k=1; k<=j; ++k){
                    f[i][j] = max(f[i][j], min(f[i-1][j-k], p[i]/k));
                }
            }
        }

        memset(g, INF, sizeof(g));

        for(int i=1; i<=m; ++i){
            g[i-1][0] = 0;
            for(int j=1; j<=n; ++j){
                g[i][j] = g[i-1][j];
                for(int k=1; k<=j; ++k){
                    int s = p[i]/k;
                    if(s >= f[m][n]){
                        g[i][j] = min(g[i][j], g[i-1][j-k]+p[i]);
                    }
                }
            }
        }

        printf("%d %d\n", f[m][n], f[m][n]==0?0:g[m][n]);
    }
    return 0;
}
