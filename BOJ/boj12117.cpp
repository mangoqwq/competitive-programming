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
	for (int tc = 1; tc <= T; ++tc) [&]() {
		cout << "Case #" << tc << ": ";
		string S; cin >> S;
		int N = S.size();
		vector<vector<int>> lst(N+2, vector<int>(10, -1));
		for (int i = 1; i <= N; ++i) {
			lst[i] = lst[i-1];
			lst[i][S[i-1] - '0'] = i;
		}

		const int MA = 150;
		vector<vector<int>> dp(N+1, vector<int>(MA));
		for (int i = 0; i <= N; ++i) {
			dp[i][0] = i+1;
		}
		for (int k = 1; k < MA; ++k) {
			for (int i = 0; i <= N; ++i) {
				dp[i][k] = dp[i][k-1];
				if (dp[i][k] == N+1) continue;
				for (int d = 1; d < 10; ++d) {
					if (d > k || lst[dp[i][k-d]][d] <= i) continue;
					int j = lst[dp[i][k-d]][d];
					dp[i][k] = max(dp[i][k], dp[j][k-d]);
				}
			}
		}
		for (int k = 0; k < MA; ++k) {
			if (dp[0][k] == N+1) {
				cout << k << '\n';
				return;
			}
		}
	}();
}
