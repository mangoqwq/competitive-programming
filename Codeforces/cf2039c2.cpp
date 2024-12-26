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
		for (ll y = 1; y <= min(x, M); ++y) {
			ll v = x ^ y;
			if (v % x != 0 && v % y == 0) debug(y), ans++;
		}
		if (M >= x) {
			ll k = (M - x) / x;
			if (k == 0) ans++;
			else if (k == 1) ans++;
			else if (k >= 2) ans += k;
			debug(k);
			for (ll i = k+1; i < k+10; ++i) {
				ll y = ((i * x) ^ x);
				if (y <= M && y > 0) debug(i, (i * x) ^ x), ans++;
			}
		}
		cout << ans << '\n';
	}();
}
