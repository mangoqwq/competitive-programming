#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <bits/stdc++.h>

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
//
pair<vector<vector<int>>, int> CentroidTree(vector<vector<int>> adj) {
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
	return {ret, rt};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	auto [tree, rt] = CentroidTree(adj);
	vector<int> vis(N);
	ll ans = 0;

	vector<int> acc(N + 1), cur(N + 1);
	auto dfs = [&](auto self, int v, int p, int d) -> void {
		if (d > K) return;
		cur[d]++;
		for (int to : adj[v]) {
			if (to == p || vis[to]) continue;
			self(self, to, v, d + 1);
		}
	};

	auto go = [&](auto self, int v) -> void {
		vis[v] = 1;
		acc[0] = 1;
		for (int to : adj[v]) {
			if (vis[to]) continue;
			dfs(dfs, to, v, 1);
			for (int i = 1; i <= N; ++i) {
				if (cur[i] == 0) break;
				if (K - i >= 0) ans += 1LL * cur[i] * acc[K - i];
			}
			for (int i = 1; i <= N; ++i) {
				if (cur[i] == 0) break;
				acc[i] += cur[i];
				cur[i] = 0;
			}
		}
		for (int i = 0; i <= N; ++i) {
			if (acc[i] == 0) break;
			acc[i] = 0;
		}

		for (int to : tree[v]) {
			self(self, to);
		}
	};
	go(go, rt);
	cout << ans << '\n';
}
