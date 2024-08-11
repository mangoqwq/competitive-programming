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
		vector<vector<int>> dp(N+1, vector<int>(N+1, 1e9));
		for (int i = 0; i <= N; ++i) dp[i][i] = 0;
		for (int len = 1; len <= N; ++len) {
			for (int l = 0; l + len <= N; ++l) {
				int r = l + len;
				for (int i = l+1; i < r; ++i) {
					int lc = dp[l+1][i];
					int rc = dp[i+1][r];
					if (lc > a[l]) continue;
					int add = 1 + ((i) - (l+1)) / 2;
					dp[l][r] = min(dp[l][r], max(a[l], rc - add));
				}
			}
		}
		
		vector<int> ans(N+1);
		ans[0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i+2; j <= N; j += 2) {
				if (ans[i] >= dp[i][j]) {
					ans[j] = max(ans[j], ans[i] + (j-i) / 2);
				}
			}
			ans[i+1] = max(ans[i+1], ans[i]);
		}
		cout << ans[N] << '\n';
	}();
}
