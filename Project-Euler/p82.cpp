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
	int N = 80;
	string line;
	vector<vector<int>> mat;
	while (getline(cin, line)) {
		istringstream iss(line);
		mat.push_back({});
		for (int i = 0; i < N; ++i) {
			int x; char c; iss >> x >> c;
			mat.back().push_back(x);
		}
	}

	vector<vector<int>> dp(N, vector<int>(N, 1e9));
	for (int i = 0; i < N; ++i) {
		dp[i][0] = mat[i][0];
	}
	for (int j = 1; j < N; ++j) {
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				if (i) dp[i][j] = min({dp[i][j], dp[i][j-1] + mat[i][j], dp[i-1][j] + mat[i][j]});
				if (i < N-1) dp[i][j] = min({dp[i][j], dp[i][j-1] + mat[i][j], dp[i+1][j] + mat[i][j]});
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, dp[i][N-1]);
	}
	cout << ans << '\n';
}

