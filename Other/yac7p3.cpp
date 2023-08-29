#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// Utilities to make functional graph easier to work with
// Supply successor array (0-indexed), returns two vectors of vectors
// First one contains a list of all the cycles
// Second one contains an directed adjacency list with the reverse of all tree edges
// Runtime: O(N)
// Tested:
// https://cses.fi/problemset/task/1160
pair<vector<vector<int>>, vector<vector<int>>> FunctionalGraph(vector<int> succ) {
	int N = succ.size();
	vector<vector<int>> cycles, tree_adj(N);
	vector<int> vis(N), cycle(N), cur;
	auto dfs = [&](auto self, int v) -> void {
		vis[v] = 1; cur.push_back(v);
		if (vis[succ[v]] == 1) {
			cycles.push_back({});
			for (int i = cur.size()-1; i >= 0; --i) {
				int x = cur[i];
				cycles.back().push_back(x);
				cycle[x] = 1;
				if (succ[v] == x) break;
			}
			reverse(cycles.back().begin(), cycles.back().end());
		}
		else if (vis[succ[v]] == 0) {
			self(self, succ[v]);
		}
		vis[v] = 2; cur.pop_back();
	};

	for (int i = 0; i < N; ++i) {
		if (!vis[i]) dfs(dfs, i);
	}
	for (int i = 0; i < N; ++i) {
		if (cycle[i] && cycle[succ[i]]) continue;
		tree_adj[succ[i]].push_back(i);
	}
	return {cycles, tree_adj};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> succ(N);
	for (int i = 0; i < N; ++i) {
		cin >> succ[i];
		succ[i]--;
	}

{
	auto [cycles, adj] = FunctionalGraph(succ);
	vector<int> far(N);
	vector<int> rt(N);
	for (auto cycle : cycles) {
		auto dfs = [&](auto self, int v, int d, int base) -> void {
			rt[v] = base;
			far[v] = d;
			for (int to : adj[v]) {
				self(self, to, d+1, base);
			}
		};
		for (int c : cycle) {
			for (int to : adj[c]) {
				dfs(dfs, to, 1, to);
			}
		}
	}
	int mx = max_element(far.begin(), far.end()) - far.begin();
	if (far[mx] == 0) {
		cout << 0+1 << " " << succ[0]+1 << '\n';
	}
	else {
		cout << rt[mx]+1 << " " << mx+1 << '\n';
		succ[rt[mx]] = mx;
	}
}

	auto [cycles, adj] = FunctionalGraph(succ);
	int T = 0;
	vector<int> ans(N);
	for (auto cycle : cycles) {
		map<int, int> mp;
		for (int i = 0; i < cycle.size(); ++i) {
			mp[i] = T++;
		}
		auto dfs = [&](auto self, int v, int d) -> void {
			ans[v] = mp[d];
			for (int to : adj[v]) {
				self(self, to, (d-1+cycle.size()) % cycle.size());
			}
		};
		for (int i = 0; i < cycle.size(); ++i) {
			dfs(dfs, cycle[i], i);
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << ans[i]+1 << (i == N-1 ? '\n' : ' ');
	}
}
