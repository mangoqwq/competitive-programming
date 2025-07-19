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
	int N = 100;
	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	for (int k = 0; k <= N; ++k) {
		dp[0][k] = 1;
	}
	for (int n = 1; n <= N; ++n) {
		for (int k = 1; k <= N; ++k) {
			for (int j = 1; j <= min(n, k); ++j) {
				dp[n][k] += dp[n - j][j];
			}
		}
	}
	cout << dp[N][N] - 1 << '\n';
}
