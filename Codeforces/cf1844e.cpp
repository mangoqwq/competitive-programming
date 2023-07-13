#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

struct DisjointSet {
	vector<int> p, sz;
	DisjointSet(int N) {
		p.resize(N);
		iota(p.begin(), p.end(), 0);
		sz.resize(N, 1);
	}
	int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
	bool unite(int a, int b) {
		a = root(a), b = root(b);
		if (a == b) return 0;
		if (sz[b] > sz[a]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		return 1;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N, M, K; cin >> N >> M >> K;
		N--, M--;
		vector<pair<int, int>> diffs;
		DisjointSet dsu(N+M);
		vector<vector<int>> demand(N-1, vector<int>(M-1, -1));
		for (int i = 0; i < K; ++i) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			bool inv = y2 < y1;
			int x = min(x1, x2), y = min(y1, y2);
			x--, y--;
			int n1 = x, n2 = N + y;
			if (inv) diffs.push_back({n1, n2});
			else dsu.unite(n1, n2);
		}

		bool bad = 0;
		struct Edge { int to, id; };
		vector<vector<Edge>> adj(N+M);
		for (int i = 0; i < diffs.size(); ++i) {
			auto [a, b] = diffs[i];
			a = dsu.root(a), b = dsu.root(b);
			if (a == b) bad = 1;
			adj[a].push_back({b, i});
			adj[b].push_back({a, i});
			debug(a, b);
		}

		vector<int> c(N+M, -1);
		auto dfs = [&](auto self, int v, int p) -> void {
			debug(v);
			for (auto [to, id] : adj[v]) {
				if (id == p) continue;
				if (c[to] == -1) {
					c[to] = c[v] ^ 1;
					self(self, to, id);
				}
				else {
					if (c[to] == c[v]) bad = 1;
				}
			}
		};
		for (int i = 0; i < N+M; ++i) {
			if (dsu.root(i) != i) continue;
			if (c[i] == -1) c[i] = 0, dfs(dfs, i, -1);
		}
		cout << (bad ? "NO" : "YES") << '\n';
	}();
}
