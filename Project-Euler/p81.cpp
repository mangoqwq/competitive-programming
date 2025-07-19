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

	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1e9));
	dp[0][1] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + mat[i - 1][j - 1];
		}
	}
	cout << dp[N][N] << '\n';
}

