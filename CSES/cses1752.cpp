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
	int N, D; cin >> N >> D;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	set<int> ans;
	vector<int> keep(N, -1);
	vector<int> d(N);
	auto dfs = [&](auto self, int v, int p) -> void {
		using pii = pair<int, int>;
		vector<pii> ds;
		for (int to : adj[v]) {
			if (to == p) continue;
			self(self, to, v);
			ds.push_back({d[to] + 1, keep[to]});
		}
		if (ds.empty()) {
			d[v] = 0;
			keep[v] = v;
			ans.insert(v);
		}
		else {
			sort(ds.begin(), ds.end());
			debug(v, ds);
			int p = 0;
			while (p != ds.size()-1 && ds[p].first + ds[p+1].first < D) {
				ans.erase(ds[p].second);
				p++;
			}
			if (ds[p].first >= D) {
				ans.insert(v);
				d[v] = 0, keep[v] = v;
			}
			else {
				tie(d[v], keep[v]) = ds[p];
			}
		}
	};
	dfs(dfs, 0, 0);
	cout << ans.size() << '\n';
	for (int x : ans) cout << x+1 << " ";
	cout << '\n';
}
