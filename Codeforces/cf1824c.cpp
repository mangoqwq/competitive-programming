#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> val(N);
	for (int i = 0; i < N; ++i) {
		cin >> val[i];
	}

	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> lz(N);
	unordered_map<int, ll> cnt;
	using pii = pair<ll, int>;
	vector<set<pii>> vals(N);
	int ans = 0;
	auto dfs = [&](auto self, int v, int p) -> void {
		vector<int> children;
		for (int to : adj[v]) {
			if (to == p) continue;
			children.push_back(to);
			self(self, to, v);
		}

		if (children.empty()) {
			vals[v] = {{1, 0}};
			lz[v] = val[v];
		}
		else {
			sort(children.begin(), children.end(), [&](int a, int b) {
				return vals[a].size() > vals[b].size();
			});

			cnt.clear();
			swap(vals[v], vals[children[0]]);
			lz[v] = lz[children[0]];
			ll base = vals[v].begin()->first;
			for (int i = 1; i < children.size(); ++i) {
				int to = children[i];
				for (auto [_, x] : vals[to]) {
					x ^= lz[to] ^ lz[v];
					if (vals[v].count({base, x})) {
						cnt[x] = base;
					}
					if (!cnt.count(x)) {
						cnt[x] = base;
						vals[v].insert({cnt[x], x});
					}
					else {
						vals[v].erase({cnt[x], x});
						cnt[x]++;
						vals[v].insert({cnt[x], x});
					}
				}
			}
			for (int to : children) {
				vals[to].clear();
			}
			lz[v] ^= val[v];

			while (vals[v].begin()->first < (--vals[v].end())->first) {
				debug("a");
				vals[v].erase(vals[v].begin());
			}
			ans += children.size() - ((--vals[v].end())->first - base + 1);
		}
		debug(v+1, vals[v], lz[v]);
	};
	dfs(dfs, 0, 0);
	ans++;
	for (auto [_, x] : vals[0]) {
		if (lz[0] == x) ans--;
	}
	cout << ans << '\n';
}
