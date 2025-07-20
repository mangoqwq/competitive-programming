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
		vector<int> a(N), fix(N+1, -1);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			if (a[i]) fix[a[i]] = i % 2;
		}
		int evens = (N + 1) / 2;
		int odds = N / 2;
		vector<ll> dp(evens + 1, -1e18);
		dp[0] = 0;
		for (int i = 1; i <= N; ++i) {
			vector<ll> nxt(evens + 1, -1e18);
			for (int j = 0; j <= evens; ++j) {
				int k = i - 1 - j;
				// j = # evens, k = # odds
				if (fix[i] == -1 || fix[i] == 0) { // put in even
					if (j < evens)
						nxt[j+1] = max(nxt[j+1], dp[j] + i * (1 + j + odds - k));
				}
				if (fix[i] == -1 || fix[i] == 1) { // put in odd
					if (k < odds)
						nxt[j] = max(nxt[j], dp[j] + i * (1 + k + evens - j));
				}
			}
			debug(nxt);
			dp = nxt;
		}
		ll ans = dp[evens];
		cout << ans << '\n';
	}();
}
