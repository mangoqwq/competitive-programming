#include <algorithm>
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
	const int MD = 1e6;
	vector<pair<int, int>> vec;
	for (int d = 1; d <= MD; ++d) {
		if (d == 7) continue;
		int n = 3 * d / 7;
		if (gcd(n, d) == 1) {
			vec.push_back({n, d});
		}
	}
	auto ans = *ranges::max_element(vec, [&](pair<int, int> a, pair<int, int> b) { return 1LL * a.first * b.second < 1LL * b.first * a.second; });
	cout << ans.first << '\n';
}
