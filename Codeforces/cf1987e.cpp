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
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		vector<vector<int>> adj(N);
		for (int i = 1; i < N; ++i) {
			int p; cin >> p; p--;
			adj[p].push_back(i);
		}

		ll ans = 0;
		auto dfs = [&](auto self, int v) -> vector<ll> {
			if (adj[v].size() == 0) {
				return {(ll)1e9};
			}
			vector<ll> cost;
			ll have = 0;
			for (int to : adj[v]) {
				auto nxt = self(self, to);
				nxt.insert(nxt.begin(), 0);
				while (cost.size() < nxt.size()) cost.push_back(0);
				for (int i = 0; i < (int)nxt.size(); ++i) {
					cost[i] += nxt[i];
				}
				have += a[to];
			}
			ll need = max(0LL, a[v] - have);
			for (int i = 0; i < (int)cost.size(); ++i) {
				ll del = min(need, cost[i]);
				cost[i] -= del;
				need -= del;
				ans += i * del;
			}
			cost[0] += max(0LL, have - a[v]);
			return cost;
		};
		dfs(dfs, 0);
		cout << ans << '\n';
	}();
}
