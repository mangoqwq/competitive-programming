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
	vector<vector<int>> grid(N, vector<int>(N)), dp(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> grid[i][j];
			if (i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if (i && j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			dp[i][j] += grid[i][j];
		}
	}
	cout << *ranges::max_element(dp.back()) << '\n';
}
