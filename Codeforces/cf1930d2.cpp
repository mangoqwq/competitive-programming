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
		string s; cin >> s;
		ll ans = 0;
		vector<ll> cnt(3, 0), dp(3, 0);
		for (int i = 0; i < N; ++i) {
			if (s[i] == '0') {
				cnt = {0, cnt[0], cnt[1] + cnt[2] + 1};
				dp = {0, dp[0], dp[1] + dp[2]};
			}
			else {
				cnt = {1 + cnt[2], cnt[0], cnt[1]};
				dp = {dp[2] + cnt[0], dp[0], dp[1]};
			}
			ans += dp[0] + dp[1] + dp[2];
		}
		cout << ans << '\n';
	}();
}
