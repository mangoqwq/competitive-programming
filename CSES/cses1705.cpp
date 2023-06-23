#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// ** BEGIN TEMPLATE **
// Builds the biconnected components (BCC) tree of a connected graph (0-indexed)
// For each BCC of the graph, creates a dummy node in the BCC tree
// that is connected to each vertex of the BCC
// The number of BCCs is |V(bcc tree)| - |V(original graph)|
// Recover BCCs by looking at neighbours of dummy nodes
// Returns adj list of BCC Tree
// Runtime: O(N)
vector<vector<int>> BCCTree(vector<vector<int>> adj) {
	int N = adj.size();
	vector<vector<int>> tree(N);
	vector<int> up(N), in(N), stk;
	int dummy = N;
	int T = 0;
	auto dfs = [&](auto self, int v) -> void {
		up[v] = in[v] = ++T;
		stk.push_back(v);
		for (int to : adj[v]) {
			if (in[to]) up[v] = min(up[v], in[to]);
			else {
				self(self, to);
				up[v] = min(up[v], up[to]);
				if (up[to] >= in[v]) {
					tree.push_back({});
					stk.push_back(v);
					while (true) {
						int u = stk.back(); stk.pop_back();
						tree[dummy].push_back(u);
						tree[u].push_back(dummy);
						if (u == to) break;
					}
					dummy++;
				}
			}
		}
	};
	dfs(dfs, 0);
	return tree;
}

// ** BEGIN TEMPLATE **
struct LCA {
	int N, L;
	vector<vector<int>> up;
	vector<int> in, out;
	LCA (vector<vector<int>> adj, int rt) 
		: N(adj.size()), L(__lg(N)), up(N, vector<int>(L)), in(N), out(N) {
		int T = 0;
		auto dfs = [&](auto self, int v, int p) -> void {
			in[v] = ++T; up[v][0] = p;
			for (int i = 1; i < L; ++i) {
				up[v][i] = up[up[v][i-1]][i-1];
			}
			for (int to : adj[v]) {
				if (to == p) continue;
				self(self, to, v);
			}
			out[v] = T;
		};
		dfs(dfs, rt, rt);
	}
	bool is_anc(int a, int b) {
		return in[a] <= in[b] && out[a] >= out[b];
	}
	int lca(int a, int b) {
		if (is_anc(a, b)) return a;
		if (is_anc(b, a)) return b;
		for (int i = L-1; i >= 0; --i) {
			if (!is_anc(up[a][i], b)) a = up[a][i];
		}
		return up[a][0];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, Q; cin >> N >> M >> Q;
	vector<vector<int>> adj(N);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	auto tree = BCCTree(adj);
	LCA t(tree, 0);
	while (Q--) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--, c--;
		int lca = t.lca(a, b);
		bool can = 1;
		if (t.is_anc(lca, c) && t.is_anc(c, a)) can = 0;
		if (t.is_anc(lca, c) && t.is_anc(c, b)) can = 0;
		cout << (can ? "YES" : "NO") << '\n';
	}
}
