#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

const int MN = 2e5;
const int L = 30;

int N, Q, a[MN], st[2*MN][L], buf[MN], P;
ll psa[MN+1][L];

void qry(int l, int r) {
	P = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (1 & l) buf[P++] = l++;
		if (1 & r) buf[P++] = --r;
	}
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	memset(st, 0x3f, sizeof st);
	for (int i = 0; i < N; ++i) {
		st[i+N][__lg(a[i])] = a[i];
		psa[i+1][__lg(a[i])] = a[i];
	}
 
	for (int b = 0; b < 30; ++b) {
		for (int i = N-1; i > 0; --i) {
			st[i][b] = min(st[i<<1][b], st[i<<1|1][b]);
		}
		for (int i = 1; i <= N; ++i) {
			psa[i][b] += psa[i-1][b];
		}
	}
 
	while (Q--) {
		int l, r; cin >> l >> r; l--;
		ll ans = 1; qry(l, r);
		for (int i = 0; i < 30; ++i) {
			if (ans < (1 << (i+1))) {
				int tot = 0x3f3f3f3f;
				for (int j = 0; j < P; ++j) {
					tot = min(tot, st[buf[j]][i]);
				}
				if (tot > ans) break;
			}
			ans += psa[r][i] - psa[l][i];
		}
		cout << ans << '\n';
	}
 
}
