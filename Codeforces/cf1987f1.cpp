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
		int N; cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			int x; cin >> x; x--;
			a[i] = 1e9;
			if (i >= x && (i - x) % 2 == 0) {
				a[i] = (i - x) / 2;
			}
		}

		vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(N+1, -1)));
		auto go = [&](auto self, int v, int l, int r) -> int {
			if (r - l <= 1) return 0;
			int &cur = dp[v][l][r];
			if (cur != -1) return cur;
			cur = self(self, v, l+1, r);
			if (a[l] > v) return cur;
			for (int i = l+1; i < r; ++i) {
				int lc = self(self, min(a[l], v), l+1, i);
				cur = max(cur, 1 + lc + self(self, v + lc + 1, i+1, r));
			}
			return cur;
		};
		int ans = go(go, 0, 0, N);
		cout << ans << '\n';
	}();
}
