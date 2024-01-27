#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N; ll K; cin >> N >> K;
		vector<ll> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			a[i] -= K;
		}
		sort(a.begin(), a.end());
		if (a[0] == a.back()) {
			cout << 0 << '\n';
			return;
		}
		if (a[0] <= 0 && a.back() >= 0) {
			cout << -1 << '\n';
			return;
		}
		ll g = accumulate(a.begin(), a.end(), a[0], [&](ll x, ll y) { return gcd(x, y); });
		ll ans = 0;
		for (ll x : a) ans += abs(x / g) - 1;
		cout << ans << '\n';
	}();
}
