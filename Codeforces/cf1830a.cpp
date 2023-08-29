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
		struct Edge { int to, id; };
		vector<vector<Edge>> adj(N);
		for (int i = 0; i < N-1; ++i) {
			int a, b; cin >> a >> b;
			a--, b--;
			adj[a].push_back({b, i});
			adj[b].push_back({a, i});
		}

		int ans = 0;
		auto dfs = [&](auto self, int v, int p, int cur) -> void {
			ans = max(ans, cur);
			for (auto [to, id] : adj[v]) {
				if (id == p) continue;
				self(self, to, id, cur + (id < p));
			}
		};
		dfs(dfs, 0, 1e9, 0);
		cout << ans << '\n';
	}();
}
