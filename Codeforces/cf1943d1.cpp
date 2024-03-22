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
		int N, K, mod; cin >> N >> K >> mod;
		vector<vector<ll>> dp(K+1, vector<ll>(K+1));
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i) {
			for (int a = 1; a <= K; ++a) {
				for (int b = 0; b <= K; ++b) {
					dp[a][b] += dp[a-1][b];
					dp[a][b] %= mod;
				}
			}
			vector<vector<ll>> nxt(K+1, vector<ll>(K+1));
			for (int b = 0; b <= K; ++b) {
				for (int c = 0; c <= K; ++c) {
					nxt[b][c] += dp[K][b];
					if (b-c > 0) nxt[b][c] -= dp[b-c-1][b];
					nxt[b][c] = (nxt[b][c] % mod + mod) % mod;
				}
			}
			swap(nxt, dp);
			debug(nxt);
		}
		ll ans = 0;
		for (int a = 0; a <= K; ++a) {
			for (int b = 0; b <= a; ++b) {
				ans += dp[a][b];
				ans %= mod;
			}
		}
		cout << ans << '\n';
	}();
}
