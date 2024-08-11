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
			int x; cin >> x;
			x--;
			a[x]++;
		}
		vector<vector<int>> dp(N+1, vector<int>(N+1, 1e9));
		dp[0][0] = 0;
		for (int i = 0; i < N; ++i) {
			if (!a[i]) {
				dp[i+1] = dp[i];
				continue;
			}
			for (int cred = 0; cred < N; ++cred) {
				// let A eat
				dp[i+1][cred+1] = min(dp[i+1][cred+1], dp[i][cred] + 1);
				// let B eat
				if (cred >= a[i]) {
					dp[i+1][cred - a[i]] = min(dp[i+1][cred - a[i]], dp[i][cred]);
				}
			}
		}
		int ans = *min_element(dp[N].begin(), dp[N].end());
		cout << ans << '\n';
	}();
}
