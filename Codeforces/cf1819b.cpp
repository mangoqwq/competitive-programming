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
		int N; cin >> N;
		vector<int> a(N), b(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i] >> b[i];
		}

		vector<pair<ll, ll>> ans;
		map<ll, set<int>> xs;
		map<ll, set<int>> ys;
		auto ins = [&](int i) -> void {
			xs[a[i]].insert(i);
			ys[b[i]].insert(i);
		};
		auto rem = [&](int i) -> void {
			xs[a[i]].erase(i);
			ys[b[i]].erase(i);
		};
		for (int i = 0; i < N; ++i) ins(i);

		auto dfs = [&](auto self, int i, ll x, ll y, ll sx, ll sy) -> void {
			if (i == N) {
				ans.push_back({sx, sy});
				return;
			}
			if (!xs[x].empty()) {
				auto nxt = *xs[x].begin();
				rem(nxt);
				self(self, i+1, x, y - b[nxt], sx, sy);
				ins(nxt);
			}
			if (!ys[y].empty()) {
				auto nxt = *ys[y].begin();
				rem(nxt);
				self(self, i+1, x - a[nxt], y, sx, sy);
				ins(nxt);
			}
		};

		ll area = 0;
		for (int i = 0; i < N; ++i) {
			area += 1LL * a[i] * b[i];
		}
		int testx = (--xs.end())->first;
		int testy = (--ys.end())->first;

		auto test = [&](int d) -> void {
			ll x = d, y = area / d;
			if (x * y != area) return;
			dfs(dfs, 0, x, y, x, y);
			dfs(dfs, 0, y, x, y, x);
		};
		test(testx);
		test(testy);

		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

		cout << ans.size() << '\n';
		for (auto [x, y] : ans) {
			cout << x << " " << y << '\n';
		}
	}();
}
