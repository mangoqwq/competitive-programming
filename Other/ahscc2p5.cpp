#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, K; ll T; cin >> N >> M >> K >> T;
	vector<int> src(N, 1);
	for (int i = 0; i < K; ++i) {
		int v; cin >> v; v--;
		src[v] = 0;
	}
	struct Edge { int to; ll w; };
	vector<vector<Edge>> adj(N);
	for (int i = 0; i < M; ++i) {
		int a, b; ll w; cin >> a >> b >> w; a--, b--;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}

	struct Item {
		int v; ll d;
		bool operator<(const Item &other) const { return d > other.d; }
	};
	priority_queue<Item> pq;
	vector<ll> dist(N, 2e18);
	for (int i = 0; i < N; ++i) {
		if (!src[i]) continue;
		dist[i] = 0;
		pq.emplace(i, 0);
	}
	while (!pq.empty()) {
		auto [v, d] = pq.top(); pq.pop();
		if (dist[v] < d) continue;
		for (auto [to, w] : adj[v]) {
			ll nd = d + w;
			if (nd < dist[to]) {
				dist[to] = nd;
				pq.emplace(to, nd);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << (dist[i] > T);
	}
	cout << '\n';
}
