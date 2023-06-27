#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	struct Edge { int to; ll w; };
	vector<vector<Edge>> adj(N);
	for (int i = 0; i < M; ++i) {
		int a, b, w; cin >> a >> b >> w;
		a--, b--;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	struct Item {
		ll d; int v;
		bool operator<(const Item &other) const {
			return d > other.d;
		}
	};
	vector<ll> dist(N, 1e18);
	priority_queue<Item> pq;
	dist[N-1] = 0;
	pq.push({0, N-1});
	while (!pq.empty()) {
		auto [d, v] = pq.top(); pq.pop();
		if (d != dist[v]) continue;
		for (auto [to, w] : adj[v]) {
			ll nd = w + d;
			if (nd < dist[to]) {
				dist[to] = nd;
				pq.push({dist[to], to});
			}
		}
	}

	if (dist[0] == 1e18) {
		cout << "inf" << '\n';
		return 0;
	}

	vector<int> in(N, 1);
	in[N-1] = 0;
	map<ll, vector<int>> vals;
	for (int i = 0; i < N-1; ++i) {
		vals[dist[i]].push_back(i);
	}

	ll T = 0, K = 0;
	struct Game { vector<int> v; ll t; };
	vector<Game> games;
	for (auto [t, vs] : vals) {
		games.push_back({in, t-T});
		T = t; K++;
		for (int x : vs) in[x] = 0;
		if (!in[0]) break;
	}

	cout << T << " " << K << '\n';
	for (auto [v, t] : games) {
		for (int i = 0; i < N; ++i) cout << v[i];
		cout << " " << t << '\n';
	}
}
