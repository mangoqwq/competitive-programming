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
		int N, X; cin >> N >> X;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		auto solve = [&](int d) -> int {
			vector<int> dp(N, -1);
			map<int, int> mp;
			mp[0] = 0;
			int cur = 0;
			for (int i = 0; i < N; ++i) {
				cur ^= a[i];
				int msk = cur & (~d);
				if (mp.count(msk)) {
					dp[i] = mp[msk] + 1;
					mp[msk] = max(mp[msk], dp[i]);
				}
			}
			return dp[N-1];
		};
		int ans = solve(X);
		for (int i = 29; i >= 0; --i) {
			if (1 & (X >> i)) {
				int d = X - (1 << i);
				d = d | ((1 << i) - 1);
				int cur = solve(d);
				ans = max(ans, cur);
			}
		}
		cout << ans << '\n';
	}();
}
