#include<iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
int n;
char read_char() {
    char c;
    for (;; ) {
        c = getchar();
        if ((c >= 'A'&&c <= 'Z') || c == '.') return c;

    }
}

void get(int k, int i, int j, int p, int &x, int &y, int &z) {
    if (k == 0) { x = p; y = j; z = i; }
    if (k == 1) { x = n - 1 - j; y = p; z = i; }
    if (k == 2) { x = n - 1 - p; y = n - 1 - j; z = i; }
    if (k == 3) { x = j; y = n - p - 1; z = i; }
    if (k == 4) { x = n - 1 - i; y = j; z = p; }
    if (k == 5) { x = i; y = j; z = n - 1 - p; }
}
;
char view[6][10][10], pos[10][10][10];
int main() {

    while (cin >> n) {
        if (n == 0)break;
        REP(i, n) REP(k, 6) REP(j, n) view[k][i][j] = read_char();
        REP(i, n) REP(j, n) REP(k, n) pos[i][j][k] = '#';

        REP(k, 6) REP(i, n) REP(j, n) if (view[k][i][j] == '.') { REP(p, n) { int x, y, z; get(k, i, j, p, x, y, z); pos[x][y][z] = '.'; } };

        for (;;) {

            bool done = true;
            REP(i, n)REP(j, n)REP(k, 6) if (view[k][i][j]!='.' ) {
                REP(p, n) {
                    int x, y, z;
                    get(k, i, j, p, x, y, z);
                    if (pos[x][y][z] == '.') continue;
                    if (pos[x][y][z] == '#') { pos[x][y][z] = view[k][i][j]; break; }


                if (pos[x][y][z] == view[k][i][j]) break;
                pos[x][y][z] = '.';
                done = false;
            }
            }
            if (done) break;
        }
        int ans = 0;
        REP(i, n)REP(j, n)REP(k, n)
            if (pos[i][j][k] != '.') ans++;
        printf("Maximum weight: %d gram(s)\n", ans);
    }
    return 0;
}
