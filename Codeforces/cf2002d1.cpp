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
		int N, Q; cin >> N >> Q;
		vector<int> par(N);
		for (int i = 1; i < N; ++i) {
			cin >> par[i];
			par[i]--;
		}

		vector<int> val(N), inv(N);
		for (int i = 0; i < N; ++i) {
			cin >> val[i];
			val[i]--;
			inv[val[i]] = i;
		}

		vector<int> sz(N, 1);
		using pii = pair<int, int>;
		vector<set<pii>> chs(N);
		for (int i = N-1; i > 0; --i) {
			sz[par[i]] += sz[i];
			chs[par[i]].insert({inv[i], i});
		}

		set<int> valid;
		auto reevaluate = [&](int i) -> void {
			bool ok = [&]() -> bool {
				if (sz[i] == 1) return 1;
				int l = (chs[i].begin())->second;
				int r = (--chs[i].end())->second;
				if (inv[i] != inv[l] - 1) return 0;
				if (inv[i] + sz[i] != inv[r] + sz[r]) return 0;
				return 1;
			}();
			if (ok) valid.insert(i);
			else valid.erase(i);
		};

		for (int i = 0; i < N; ++i) {
			reevaluate(i);
		}

		for (int q = 0; q < Q; ++q) {
			int i, j; cin >> i >> j; i--, j--;
			int u = val[i], v = val[j];
			if (u) chs[par[u]].erase({inv[u], u});
			if (v) chs[par[v]].erase({inv[v], v});
			swap(val[i], val[j]);
			swap(inv[u], inv[v]);
			if (u) chs[par[u]].insert({inv[u], u});
			if (v) chs[par[v]].insert({inv[v], v});
			reevaluate(u);
			reevaluate(v);
			if (u) reevaluate(par[u]);
			if (v) reevaluate(par[v]);
			cout << ((int)valid.size() == N ? "YES" : "NO") << '\n';
		}
	}();
}
