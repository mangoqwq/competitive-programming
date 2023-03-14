#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DisjointSet{
		vector<int> p, sz;
		DisjointSet(int N){
				p.resize(N);
				iota(p.begin(), p.end(), 0);
				sz.resize(N, 1);
		}
		int root(int x){
				return p[x] == x ? x : p[x] = root(p[x]);
		}
		bool unite(int a, int b){
				a = root(a), b = root(b);
				if (a == b) return 0;
				if (sz[b] > sz[a]) swap(a, b);
				p[b] = a;
				sz[a] += sz[b];
				return 1;
		}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	struct Edge{ int u, v; };
	vector<Edge> edges(M);
	for (int i = 0; i < M; ++i){
		cin >> edges[i].u >> edges[i].v;
		edges[i].u--, edges[i].v--;
	}
	int K; cin >> K;
	vector<int> bad(M);
	for (int i = 0; i < K; ++i){
		int x; cin >> x;
		x--;
		bad[x] = 1;
	}

	DisjointSet dsu(N);
	for (int i = 0; i < M; ++i){
		if (!bad[i]) dsu.unite(edges[i].u, edges[i].v);
	}

	vector<vector<int>> adj(N);
	for (int i = 0; i < M; ++i){
		if (bad[i]){
			int a = dsu.root(edges[i].u);
			int b = dsu.root(edges[i].v);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	bool ok = [&]() -> bool {
		int odds = 0;
		for (int i = 0; i < N; ++i){
			if (dsu.root(i) != i) continue;
			if (adj[i].size() % 2 == 1) odds++;
		}
		return odds == 0 || odds == 2;
	}();
	cout << (ok ? "Yes" : "No") << '\n';
}
