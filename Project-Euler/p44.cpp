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
	int N = 1e4;
	set<ll> pent;
	for (int n = 1; n < N; ++n) {
		pent.insert(n * (3 * n - 1) / 2);
	}
	ll ans = 1e18;
	for (ll a : pent) {
		for (ll b : pent) {
			if (pent.contains(a - b) && pent.contains(a + b)) {
				ans = min(ans, abs(a - b));
			}
		}
	}
	cout << ans << '\n';
}
