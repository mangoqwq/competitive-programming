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
		int N; cin >> N;
		using pii = pair<ll, ll>;
		vector<pii> v(N);
		for (auto &[a, b] : v) {
			cin >> a >> b;
		}
		pii s, t;
		cin >> s.first >> s.second;
		cin >> t.first >> t.second;

		auto d2 = [&](pii a, pii b) -> ll {
			return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
		};
		for (auto c : v) {
			// debug(d2(s, t), d2(c, t));
			if (d2(s, t) >= d2(c, t)) {
				cout << "NO" << '\n';
				return;
			}
		}
		cout << "YES" << '\n';
	}();
}
