#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// ** BEGIN TEMPLATE **
// Utilities to make functional graph easier to work with
// Supply successor array (0-indexed), returns two vectors of vectors
// First one contains a list of all the cycles
// Second one contains an adjacency list with all edges reversed, minus the cycle edges
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
	int N, Q; cin >> N >> Q;
	vector<int> succ(N);
	for (int i = 0; i < N; ++i) {
		cin >> succ[i]; succ[i]--;
	}
	auto [cycles, adj] = FunctionalGraph(succ);

	vector<int> cc(N); int ccs = 0;
	vector<int> rt(N);
	vector<int> idx(N);
	vector<int> cycsz(N);
	for (auto cyc : cycles) {
		int i = 0;
		for (int x : cyc) {
			rt[x] = x;
			cc[x] = ccs;
			idx[x] = i++;
			cycsz[x] = cyc.size();
		}
		ccs++;
	}

	const int L = 18;
	vector<int> in(N), out(N), dist(N);
	vector<vector<int>> up(N, vector<int>(L));
	int T = 0;
	auto dfs = [&](auto self, int v, int p, int d) -> void {
		in[v] = ++T;
		up[v][0] = p;
		rt[v] = rt[p];
		cc[v] = cc[p];
		dist[v] = d;
		for (int i = 1; i < L; ++i) {
			up[v][i] = up[up[v][i-1]][i-1];
		}
		for (int to : adj[v]) {
			self(self, to, v, d+1);
		}
		out[v] = T;
	};
	for (int i = 0; i < N; ++i) {
		if (rt[i] == i) dfs(dfs, i, i, 0);
	}

	auto is_anc = [&](int a, int b) {
		return in[a] <= in[b] && out[a] >= out[b];
	};
	auto lca = [&](int a, int b) {
		if (is_anc(a, b)) return a;
		if (is_anc(b, a)) return b;
		for (int i = L-1; i >= 0; --i) {
			if (!is_anc(up[a][i], b)) a = up[a][i];
		}
		return up[a][0];
	};

	while (Q--) {
		int a, b; cin >> a >> b;
		a--, b--;
		if (rt[a] == rt[b]) {
			int l = lca(a, b);
			if (l != b) cout << -1 << '\n';
			else cout << dist[a] - dist[b] << '\n';
		}
		else {
			if (cc[a] != cc[b] || rt[b] != b) {
				cout << -1 << '\n';
			}
			else cout << dist[a] + (idx[b] - idx[rt[a]] + cycsz[b]) % cycsz[b] << '\n';
		}
	}

}
