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
	int N, T; cin >> N >> T;
	vector<map<int, vector<int>>> adj(N);
	for (int i = 0; i < T; ++i) {
		int M; cin >> M;
		for (int j = 0; j < M; ++j) {
			int a, b; cin >> a >> b; a--, b--;
			adj[a][b].push_back(i);
			adj[b][a].push_back(i);
		}
	}
	int K; cin >> K;
	vector<vector<int>> times(T);
	for (int i = 0; i < K; ++i) {
		int x; cin >> x; x--;
		times[x].push_back(i);
	}

	struct Item {
		int v, d;
		bool operator<(const Item &other) const { 
			return d > other.d;
		}
	};
	vector<int> dist(N, 1e9);
	priority_queue<Item> pq;
	dist[0] = 0;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [v, d] = pq.top(); pq.pop();
		if (d != dist[v]) continue;
		for (auto [to, vers] : adj[v]) {
			int nd = 1e9;
			for (auto ver : vers) {
				auto it = lower_bound(times[ver].begin(), times[ver].end(), d);
				if (it != times[ver].end()) nd = min(nd, *it + 1);
			}
			if (nd < dist[to]) {
				dist[to] = nd;
				pq.push({to, dist[to]});
			}
		}
	}
	if (dist[N-1] == 1e9) cout << -1 << '\n';
	else cout << dist[N-1] << '\n';
}
