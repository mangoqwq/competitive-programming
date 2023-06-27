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
		vector<int> a(N+1);
		for (int i = 1; i <= N; ++i) {
			cin >> a[i];
		}

		vector<int> dp(N+1, 1e9);
		dp[0] = 0;
		vector<int> best(N+1, 1e9);
		for (int i = 1; i <= N; ++i) {
			dp[i] = dp[i-1] + 1;
			dp[i] = min(dp[i], best[a[i]]);
			best[a[i]] = min(best[a[i]], dp[i-1]);
		}
		cout << N-dp[N] << '\n';
	}();
}
