#include <cstdio>
#include <algorithm>
using namespace std;

int cal(int A[], int N) {    //54123��>12345���Կ���12354->12345����ÿ��λ�ÿ�ʼ���жϱ��12345���貽������
    int cnt = 0, vis[505] = {0};
    for (int i = 1; i <= N; i++)  //cntͳ�Ʋ��û�λ�ĸ��������û�λ��A[j]�͵���j,������һ������
        if(!vis[i]) {            //ĳ������û����ȷλ��
            cnt++;
            for (int j = i; !vis[j]; j = A[j])   //���ѭ����һֱ��λֱ�����û�
                vis[j] = 1;
        }
    return N - cnt;
}

int main() {
    int N, A[1010], B[1010];
    while (scanf("%d", &N), N) {
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
            B[N - i + 1] = B[2 * N - i + 1] = A[i + N] = A[i];
        }

        int ans = 1 << 30;
        for (int i = 0; i < N; i++)
            ans = min(ans, cal(A + i, N));

        for (int i = 0; i < N; i++)
            ans = min(ans, cal(B + i, N));

        printf("%d\n", ans);
    }

    return 0;
}


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 505;
int p[N],k[N],w[N];
int f[N],n;

int solve(int s, int d) {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(k[i] != s) {
			cnt++;
			k[w[s]] = k[i];
			w[k[i]] = w[s];
			k[i] = s;
			w[s] = i;
		}
		s += d;
		if(s > n)
			s = 1;
		if(s <= 0)
			s = n;
	}
	return cnt;
}
int main() {
	while(scanf("%d",&n) && n) {
		for(int i = 1; i <= n; i++) {
			scanf("%d",&p[i]);
			f[p[i]] = i;
		}
		int Min = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++) {
			memcpy(k, p, sizeof(p));
			memcpy(w, f, sizeof(f));
			Min = min(Min, solve(i,-1));
			memcpy(k, p, sizeof(p));
			memcpy(w, f, sizeof(f));
			Min = min(Min, solve(i,1));
		}
		printf("%d\n",Min);
	}
}
