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
	struct Edge { int a, b, w; };
	vector<Edge> edges(N - 1);
	for (auto &[a, b, w] : edges) {
		cin >> a >> b >> w; a--, b--;
	}
	ranges::sort(edges, [&](Edge a, Edge b) {
		return a.w > b.w;
	});
	DisjointSet dsu(N);
	ll ans = 0;
	for (auto [a, b, w] : edges) {
		a = dsu.root(a);
		b = dsu.root(b);
		ans += 1LL * dsu.sz[a] * dsu.sz[b] * w;
		dsu.unite(a, b);
	}
	cout << ans << '\n';
}
