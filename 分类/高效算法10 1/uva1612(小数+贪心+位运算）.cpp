#include<cstdio>
#include<algorithm>
#include<cmath>
const int maxn = 17000;

using namespace std;

struct player{
    int score[8];
}P[maxn];

int nn, ID[maxn];
void read(int n){
        double tmp_f[3];
        int tmp_i[3];
        for(int i = 1; i <= n; i++) {
            scanf("%lf%lf%lf", &tmp_f[0], &tmp_f[1], &tmp_f[2]);
            for(int j = 0; j < 3; j++)
                tmp_i[j] = (int)(round(tmp_f[j] * 100.0));

            for(int j = 0; j < 8; j++) {
                P[i].score[j] = 0;
                for(int k = 0; k < 3; k++)
                    if(j & (1 << k))
                        P[i].score[j] += tmp_i[k];
            }
            sort(P[i].score, P[i].score + 8);
        }
}

int main() {
    int kase = 1;
    while(scanf("%d", &nn) == 1 && nn) {
            read(nn);
        for(int i = 1; i <= nn; i++)
            scanf("%d", &ID[i]);

        int MAX = P[ID[1]].score[7]; //Ì°ÐÄ²ßÂÔ
        int pre_ID = ID[1], i;
        for(i = 2; i <= nn; i++) {
            int cur_ID = ID[i];
            bool flag = false;
            for(int j = 7; j >= 0; j--) {
                if(P[cur_ID].score[j]  == MAX  && cur_ID > pre_ID) {
                    flag = true;
                    pre_ID = cur_ID;
                    break;
                }
                if(P[cur_ID].score[j] < MAX) {
                    flag = true;
                    pre_ID = cur_ID;
                    MAX = P[cur_ID].score[j];
                    break;
                }
            }
           if(!flag)
               break;
        }
        printf("Case %d: ", kase++);
        if(i != nn + 1)
            printf("No solution\n");
        else
            printf("%.2lf\n", MAX / 100.0);
    }
    return 0;
}
