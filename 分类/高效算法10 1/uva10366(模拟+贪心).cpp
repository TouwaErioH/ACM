#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
int l, r, x[N], y[N];
int L, R, idl, idr;

void read() {
	R = L = 0;
	for (int i = l; i <= r; i += 2) {
		if (i < 0) {
			scanf("%d", &x[(-i)/2]);
			if (L <= x[(-i)/2]) {
				L = x[(-i)/2]; idl = (-i)/2;
			}
		 }
		else {
			scanf("%d", &y[i/2]);
			if (R < y[i/2]) {
				R = y[i/2]; idr = i/2;
			}
		}
	}
	return ;
}

int solve() {
	l = (-l) / 2; r = r / 2;
    int tmp;
	if (R == L) {
		int k = 0, t = 0;
		tmp = x[l];
		for (int i = l; i > idl; i--) {
			k += tmp; tmp = max(tmp, x[i-1]);
		}
		tmp = y[r];
		for (int i = r; i > idr; i--) {
			t += tmp; tmp = max(tmp, y[i-1]);
		}

		return (idl + idr + 1) * R * 2 + min(k, t) * 2 * 2;//*2*2因为要从中间分开流
	} else {
		int T = min(R, L);
		int p = 0, q = 0, k = 0, t = 0;
		while (p < l && x[p] < T) p++;
		while (q < r && y[q] < T) q++;

		if (R > L) {
			tmp = y[q];
			for (int i = q; y[i] <= L; i++) {
				k += tmp; tmp = max(tmp, y[i+1]);
			}
			tmp = x[l];
			for (int i = l; i > p; i--) {
				t += tmp; tmp = max(tmp, x[i-1]);
			}

		} else {
			tmp = x[p];
			for (int i = p; x[i] <= R; i++) {
				k += tmp; tmp = max(tmp, x[i+1]); //k是从另一边流(如果开始找到的边高度等于T)，直到遇到高于T的
			}
			tmp = y[r];
			for (int i = r; i > q; i--) {
				t += tmp; tmp = max(tmp, y[i-1]);
			}
		}
		int ans = t> k ? t + k : 2 * t;       //t<k，说明确实要分开流，从T那边流走的时间;t>k，(总体积2*k+2*k+2*(t-k))
		return ans * 2 + (p + q + 1) * T * 2;
	}
}

int main() {
	while (scanf("%d%d", &l, &r) == 2 && l && r) {
        read();
		printf("%d\n", solve());
	}
	return 0;
}
