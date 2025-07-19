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
	const int mod = 1e6;
	vector<ll> p = {1};
	for (int n = 1; ; ++n) {
		ll pn = 0;
		for (ll k = -n; k <= n; ++k) {
			if (k == 0) continue;
			if (k * (3 * k - 1) / 2 <= n) {
				pn += (k % 2 ? 1 : -1) * p[n - k * (3 * k - 1) / 2];
				pn = ((pn % mod) + mod) % mod;
			}
		}
		if (pn == 0) {
			cout << n << '\n';
			break;
		}
		p.emplace_back(pn);
	}
}
