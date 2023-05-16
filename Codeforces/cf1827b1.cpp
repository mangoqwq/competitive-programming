#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}

		ll ans = 0;
		for (int l = 0; l < N; ++l) {
			vector<int> v(a.begin() + l, a.end());
			int mx = v[0];
			ll cur = 0;
			struct Range { int l, r; };
			vector<Range> stk;

			for (int i = 0; i < N-l; ++i) {
				int j = upper_bound(v.begin(), v.begin() + i, v[i]) - v.begin();

				// add range [j, i-1]
				int ql = j, qr = i-1;
				// debug(j, i);
				if (qr >= ql) {
					while (!stk.empty() && stk.back().r >= ql) {
						cur -= stk.back().r - stk.back().l + 1;
						ql = min(ql, stk.back().l);
						stk.pop_back();
					}
					stk.push_back({ql, qr});
					cur += qr - ql + 1;
				}
				// debug(ql, qr);
				ans += cur;

				// debug(cur);

				mx = max(mx, v[i]);
				v[i] = mx;
			}
		}
		cout << ans << '\n';
	}();
}
