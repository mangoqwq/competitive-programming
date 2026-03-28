#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N, Q; cin >> N >> Q;
		vector<int> a(N), psa1(N + 1), psa2(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			psa1[i + 1] = psa1[i] + a[i];
		}
		for (int i = 0; i < N - 1; ++i) {
			psa2[i + 1] = psa2[i] + (a[i] == a[i + 1]);
		}
		while (Q--) {
			int l, r; cin >> l >> r; l--;
			int len = r - l;
			int ones = psa1[r] - psa1[l];
			int eqs = psa2[r - 1] - psa2[l];
			if (len % 3 || ones % 3) {
				cout << -1 << '\n';
				continue;
			}
			int ans = len / 3;
			if (eqs == 0) ans++;
			cout << ans << '\n';
		}
	}();
}
