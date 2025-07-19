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
	int lim = 1e6 + 1;
	int ans = 0;
	vector<vector<int>> pascal(N+1, vector<int>(N+1));
	for (int n = 1; n <= N; ++n) {
		for (int k = 0; k <= n; ++k) {
			if (k == 0 || k == n) pascal[n][k] = 1;
			else pascal[n][k] = min(lim, pascal[n-1][k] + pascal[n-1][k-1]);
			if (pascal[n][k] >= lim) ans++;
		}
	}
	cout << ans << '\n';
}
