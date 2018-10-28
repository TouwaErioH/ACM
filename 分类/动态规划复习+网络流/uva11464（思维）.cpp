#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstring>
#define INF 10000000
int grid[20][20];
int temp[20][20];
int N;

int check(int k) {
    memset(temp,0,sizeof(temp));
    int sum = 0;
    for(int i = 0 ; i < N; i++){
        if(k & (1 << i))  temp[0][i] = 1;
        else if(grid[0][i] == 1) return INF;
        }
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < N; j++) {
                sum = 0;
                if(i > 1) sum += temp[i - 2][j];
                if(j > 0) sum += temp[i - 1][j - 1];
                if(j < N - 1) sum += temp[i - 1][j + 1];
                temp[i][j] = sum % 2;
                if(grid[i][j] == 1 && temp[i][j] == 0) return INF;
            }
        }
        int cnt = 0;
        for(int i = 0 ; i <N; i++)
            for(int j = 0 ; j < N; j++) {
                if(temp[i][j] != grid[i][j])
                    cnt++;
            }
        return cnt;
}
int main() {
    int T,cases = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i = 0; i < N ; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%d",&grid[i][j]);
            }
        }
        int ans = INF;
        for(int i = 0 ; i < (1 << N); i++) {
            ans = min(ans,check(i));
        }
        printf("Case %d: ",cases++);
        if(ans == INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
