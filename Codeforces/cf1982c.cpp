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
		int N, L, R; cin >> N >> L >> R;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		vector<int> dp(N+1);
		dp[0] = 0;
		int p = 0, sum = 0;
		for (int i = 0; i < N; ++i) {
			dp[i+1] = dp[i];
			sum += a[i];
			while (sum > R) sum -= a[p++];
			while (p <= i && sum - a[p] >= L) sum -= a[p++];
			if (sum >= L) dp[i+1] = max(dp[i+1], dp[p] + 1);
		}
		debug(dp);
		cout << dp[N] << '\n';
	}();
}
