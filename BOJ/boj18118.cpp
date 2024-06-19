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
		int N, M; cin >> N >> M;
		vector<vector<ll>> dp(N+1, vector<ll>(M, -1));
		dp[0][0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (dp[i][j] == -1) continue;
				for (int c = 0; c <= 9; ++c) {
					ll &nxt = dp[i+1][(j * 10 + c) % M];
					nxt = max(nxt, dp[i][j] * 10 + c);
				}
				ll &nxt = dp[i+1][(j * 100 + 11) % M];
				nxt = max(nxt, dp[i][j] * 100 + 11);
			}
		}
		cout << dp[N][0] << '\n';
	}();
}
