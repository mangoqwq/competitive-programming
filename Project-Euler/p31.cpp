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
	int N = 200;
	vector<int> dp(N + 1);
	dp[0] = 1;
	for (int c : {1, 2, 5, 10, 20, 50, 100, 200}) {
		for (int i = c; i <= N; ++i) {
			dp[i] += dp[i - c];
		}
	}
	cout << dp[200] << '\n';
}
