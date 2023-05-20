#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// Builds the centroid tree of a tree (0-indexed)
// Returns {adjacency list, root (first centroid)}
// Runtime: O(NlogN)
// Tested:
// https://cses.fi/problemset/task/2079/
// https://cses.fi/problemset/task/2080/
pair<vector<vector<int>>, int> CentroidTree(const vector<vector<int>> &adj) {
	int N = adj.size();
	vector<int> sz(N), vis(N);

	auto dfs = [&](auto self, int v, int p) -> int {
		sz[v] = 1;
		for (int to : adj[v]) {
			if (to == p || vis[to]) continue;
			sz[v] += self(self, to, v);
		}
		return sz[v];
	};

	auto locate = [&](auto self, int v, int p, int src) -> int {
		for (int to : adj[v]) {
			if (to == p || vis[to]) continue;
			if (2 * sz[to] > sz[src]) return self(self, to, v, src);
		}
		return v;
	};

	vector<vector<int>> ret(N);
	auto go = [&](auto self, int v) -> int {
		dfs(dfs, v, v);
		v = locate(locate, v, v, v);
		vis[v] = 1;
		for (int to : adj[v]) {
			if (vis[to]) continue;
			ret[v].push_back(self(self, to));
		}
		return v;
	};
	int rt = go(go, 0);
	return { ret, rt };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K1, K2; cin >> N >> K1 >> K2;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	auto [tree, rt] = CentroidTree(adj);
	vector<int> vis(N);
	vector<int> cur(N);
	vector<int> tot(N);

	auto dfs = [&](auto self, int v, int p, int d) -> void {
		if (d > K2) return;
		cur[d]++;
		for (int to : adj[v]) {
			if (to == p || vis[to]) continue;
			self(self, to, v, d+1);
		}
	};

	auto count = [&](const vector<int> &vec) -> ll {
		int n = K2+1, l = K2+1, r = K2+1;
		for (int i = 1; i <= K2; ++i) {
			if (!vec[i]) {
				n = l = r = i;
				break;
			}
		}
		ll ret = 0, cur = 0;
		for (int i = 0; i <= n; ++i) {
			while (l && (l-1) + i >= K1) {
				l--;
				cur += vec[l];
			}
			while (r && r + i > K2) {
				cur -= vec[r];
				r--;
			}
			ret += cur * vec[i];
		}
		return ret;
	};
	
	ll ans = 0;
	auto go = [&](auto self, int v) -> void {
		ll norm = 0; // centroid <-> subtree
		ll cross = 0; // subtree <-> other subtree (paths that cross centroid)
		for (int to : adj[v]) {
			if (vis[to]) continue;
			dfs(dfs, to, v, 1);
			cross -= count(cur);
			for (int i = 1; i <= K2 && cur[i]; ++i) {
				if (i >= K1 && i <= K2) norm += cur[i];
				tot[i] += cur[i];
				cur[i] = 0;
			}
		}
		cross += count(tot);
		ans += cross / 2;
		ans += norm;
		for (int i = 1; i <= K2 && tot[i]; ++i) {
			tot[i] = 0;
		}

		vis[v] = 1;
		for (int to : tree[v]) {
			self(self, to);
		}
	};
	go(go, rt);
	cout << ans << '\n';
}

