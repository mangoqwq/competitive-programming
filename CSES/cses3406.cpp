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
	auto tri = [&](ll n) -> bool {
		n = 8 * n + 1;
		ll sqr = sqrt(n) + 1e-9;
		return sqr * sqr == n;
	};
	int T; cin >> T;
	while (T--) [&]() {
		ll N; cin >> N;
		if (tri(N)) {
			cout << 1 << '\n';
			return;
		}
		for (ll i = 1; i * (i + 1) / 2 < N; ++i) {
			if (tri(N - (i * (i + 1) / 2))) {
				cout << 2 << '\n';
				return;
			}
		}
		cout << 3 << '\n';
	}();
}
