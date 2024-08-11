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
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; cin >> N >> M;
		vector<int> h(N);
		for (int i = 0; i < N; ++i) {
			cin >> h[i];
		}
		vector<vector<int>> adj(N, vector<int>(N, -1));
		vector<vector<int>> edges(N);
		for (int i = 0; i < M; ++i) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			if (adj[a][b] == -1) adj[a][b] = adj[b][a] = c;
			else adj[a][b] = adj[b][a] = min(adj[a][b], c);
			if (h[a] < h[b]) edges[b].push_back(a);
			else edges[a].push_back(b);
		}
		vector<int> ord(N);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&](int i, int j) { return h[i] < h[j]; });
		pair<int, int> ans = {(int)1e9, (int)1e9};
		for (int base : ord) {
			int roof = -1;
			DisjointSet dsu(N);
			for (int v : ord) {
				if (h[v] < h[base]) continue;
				for (int to : edges[v]) {
					if (h[to] < h[base]) continue;
					dsu.unite(v, to);
				}
				if (dsu.root(0) == dsu.root(N-1)) {
					roof = v;
					break;
				}
			}
			if (roof == -1) break;
			debug(h[base], h[roof]);
			vector<int> vis(N), dist(N, 1e9);
			dist[0] = 0;
			while (true) {
				int argmn = -1;
				for (int v = 0; v < N; ++v) {
					if (vis[v]) continue;
					if (h[v] < h[base] || h[v] > h[roof]) continue;
					if (argmn == -1 || dist[v] < dist[argmn]) {
						argmn = v;
					}
				}
				int v = argmn;
				if (argmn == -1) break;
				for (int to = 0; to < N; ++to) {
					if (h[to] < h[base] || h[to] > h[roof]) continue;
					if (adj[v][to] == -1) continue;
					dist[to] = min(dist[v] + adj[v][to], dist[to]);
				}
				vis[v] = 1;
			}
			debug(dist[N-1]);
			ans = min(ans, {h[roof] - h[base], dist[N-1]});
		}
		cout << ans.first << " " << ans.second << '\n';
	}();
}
