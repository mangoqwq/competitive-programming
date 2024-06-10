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
		ll N, X, Y; cin >> N >> X >> Y;
		vector<ll> a(X);
		for (int i = 0; i < X; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		a.push_back(a[0] + N);
		vector<pair<int, ll>> lens;
		ll ans = X - 2;
		for (int i = 1; i <= X; ++i) {
			ll l = a[i] - a[i-1] - 1;
			if (l == 1) {
				ans++;
			}
			if (l >= 2) {
				if (l % 2 == 0) {
					lens.push_back({1, l/2});
				}
				else {
					lens.push_back({0, l/2});
				}
			}
		}
		sort(lens.begin(), lens.end());
		debug(lens);
		for (auto [bon, l] : lens) {
			ll del = min(Y, l);
			l -= del; Y -= del;
			ans += del * 2;
			if (l == 0 && !bon) ans++;
		}
		cout << ans << '\n';
	}();
}
