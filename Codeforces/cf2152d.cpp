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
		vector<int> a(N), lg(N + 1), plus(N + 1), red(N + 1);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			int l = __lg(a[i]);
			lg[i + 1] = lg[i] + l;
			plus[i + 1] = plus[i] + (a[i] != (1 << l));
			red[i + 1] = red[i] + (a[i] == ((1 << l) + 1));
		}
		while (Q--) {
			int l, r; cin >> l >> r; l--;
			int ans = lg[r] - lg[l];
			ans += plus[r] - plus[l];
			ans -= (red[r] - red[l] + 1) / 2;
			cout << ans << '\n';
		}
	}();
}
