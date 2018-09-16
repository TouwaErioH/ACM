#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> R;
int N, L, P;
R A[1000005];
void solve() {
    int sumo = P;
    int count = 0;
    priority_queue<int> que;
    for (int i = 0; i <= N; i++) {
        while (sumo < A[i].first) {
            if (que.empty()) {
                puts("-1");
                return;
            }
            else {
                sumo += que.top();
                que.pop();
                count++;
            }
        }
        que.push(A[i].second);
    }
    cout << count << endl;
}
bool cmp(const R &a, const R &b) {
    return a.first < b.first;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    cin >> L >> P;
    for (int i = 0; i<N; i++)
    {
        A[i].first = L - A[i].first;
    }
    A[N] = R(L,0);
    sort(A, A + N, cmp);
    solve();
    return 0;
}
