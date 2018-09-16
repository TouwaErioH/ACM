#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
char s[55][maxn];
char ans[maxn];

int main(){
    int n, T, m, lg, ma;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++)
            scanf("%s", s[i]);
        lg = 0;
        for(int i = 0; i < n; i++){
            int cnta = 0, cntc = 0, cntg = 0, cntt = 0;
            ma = 0;
            for(int j = 0; j < m; j++){
                if('A' == s[j][i])  cnta++;
                else if('C' == s[j][i])  cntc++;
                else if('G' == s[j][i])  cntg++;
                else if('T' == s[j][i])  cntt++;
            }
            ma = max(ma, cnta);
            ma = max(ma, cntc);
            ma = max(ma, cntg);
            ma = max(ma, cntt);
            if(ma == cnta){   ans[i] = 'A';  lg += cntc; lg += cntg;  lg += cntt; }
            else if(ma == cntc){   ans[i] = 'C';  lg += cnta; lg += cntg;  lg += cntt; }
            else if(ma == cntg){   ans[i] = 'G';  lg += cntc; lg += cnta;  lg += cntt; }
            else if(ma == cntt){   ans[i] = 'T';  lg += cntc; lg += cntg;  lg += cnta; }
        }
        ans[n] = '\0';
        printf("%s\n%d\n", ans, lg);
    }
    return 0;
}
