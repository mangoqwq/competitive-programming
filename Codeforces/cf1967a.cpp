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
		}

		auto attempt = [&](ll mn) -> pair<bool, vector<ll>> {
			ll cost = 0;
			vector<ll> b = a;
			for (int i = 0; i < N; ++i) {
				if (b[i] < mn) {
					cost += mn - b[i];
					b[i] = mn;
				}
			}
			if (cost > K) return {0, {}};
			for (int i = 0; i < N; ++i) {
				if (b[i] == mn && cost < K) {
					cost++;
					b[i]++;
				}
			}
			return {1, b};
		};

		ll lo = 1, hi = 2e12;
		while (lo < hi) {
			ll mi = (lo + hi + 1) >> 1;
			auto [ok, _] = attempt(mi);
			if (ok) lo = mi;
			else hi = mi - 1;
		}
		auto [_, res] = attempt(lo);
		ll ans = 0;
		for (int i = 0; i < N; ++i) {
			ans += min(res[i], lo+1);
		}
		cout << ans - (N-1) << '\n';
	}();
}
