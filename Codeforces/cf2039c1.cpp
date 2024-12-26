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
	int T; cin >> T;
	while (T--) [&]() {
		ll x, M; cin >> x >> M;
		ll ans = 0;
		for (ll y = 1; y <= min(4*x, M); ++y) {
			if (x == y) continue;
			ll v = x ^ y;
			if (x % v == 0 || y % v == 0) ans++;
		}
		cout << ans << '\n';
	}();
}
