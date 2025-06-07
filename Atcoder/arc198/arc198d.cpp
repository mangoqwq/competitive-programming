#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
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
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char c; cin >> c;
			A[i][j] = c == '1';
		}
	}

	vector<vector<int>> step(N, vector<int>(N));
	vector<vector<int>> dist(N, vector<int>(N));
	auto dfs0 = [&](auto self, int v, int p, int rt, int di) -> void {
		step[rt][v] = di;
		dist[rt][v] = dist[rt][p] + 1;
		for (int to : adj[v]) {
			if (to == p) continue;
			self(self, to, v, rt, di);
		}
	};
	for (int i = 0; i < N; ++i) {
		for (int to : adj[i]) {
			step[i][to] = to;
			dfs0(dfs0, to, i, i, to);
		}
	}

	struct Path {
		int u, v, d;
	};
	vector<Path> paths;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (!A[i][j]) continue;
			paths.emplace_back(i, j, dist[i][j]);
		}
	}
	debug(step);
	ranges::sort(paths, {}, [&](Path p) { return p.d; });
	for (auto [u, v, d] : paths) {
		debug(u, v);
		while (true) {
			if (step[u][v] == v || u == v) break;
			int nu = step[u][v], nv = step[v][u];
			u = nu, v = nv;
			if (A[u][v]) break;
			A[u][v] = A[v][u] = 1;
		}
		debug(u, v);
	}
	for (auto v : A) {
		debug(v);
	}
	DisjointSet dsu(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j]) dsu.unite(i, j);
		}
	}
	int T = 0;
	vector<int> col(N);
	for (int i = 0; i < N; ++i) {
		if (dsu.root(i) == i) col[i] = T++;
	}
	for (int i = 0; i < N; ++i) {
		col[i] = col[dsu.root(i)];
	}

	const int base = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
	const int base2 = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
	const int mod = 1e9+7;
	vector<vector<ll>> vals(N, vector<ll>(N));
	vector<vector<ll>> vals2(N, vector<ll>(N));
	auto dfs = [&](auto self, int v, int p, int rt, ll h1, ll h2) -> void {
		h1 = (h1 * base + col[v]) % mod;
		h2 = (h2 * base2 + col[v]) % mod;
		vals[rt][v] = h1;
		vals2[rt][v] = h2;
		for (int to : adj[v]) {
			if (to == p) continue;
			self(self, to, v, rt, h1, h2);
		}
	};
	for (int i = 0; i < N; ++i) {
		dfs(dfs, i, i, i, 0, 0);
	}
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (vals[i][j] == vals[j][i] && vals2[i][j] == vals2[j][i]) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
