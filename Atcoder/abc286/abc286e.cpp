#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
	}

	vector<vector<int>> g(N, vector<int>(N));
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			char c; cin >> c;
			g[i][j] = c == 'Y';
		}
	}

	vector<vector<int>> dist(N, vector<int>(N, 1e9));
	vector<vector<ll>> souv(N, vector<ll>(N));
	auto bfs = [&](int src) -> void {
		using pii = pair<int, int>;
		queue<pii> pq;
		dist[src][src] = 0;
		pq.push({0, src});
		souv[src][src] = a[src];
		while (!pq.empty()){
			auto [d, v] = pq.front(); pq.pop();
			if (d != dist[src][v]) continue;
			for (int to = 0; to < N; ++to){
				if (!g[v][to]) continue;
				if (d + 1 < dist[src][to]){
					dist[src][to] = d + 1;
					souv[src][to] = max(souv[src][to], souv[src][v] + a[to]);
					pq.push({dist[src][to], to});
				}
				else if (d + 1 == dist[src][to]){
					souv[src][to] = max(souv[src][to], souv[src][v] + a[to]);
				}
			}
		}
	};
	for (int i = 0; i < N; ++i){
		bfs(i);
	}

	int Q; cin >> Q;
	while (Q--){
		int a, b; cin >> a >> b; a--, b--;
		if (dist[a][b] == 1e9) cout << "Impossible" << '\n';
		else{
			cout << dist[a][b] << " " << souv[a][b] << '\n';
		}
	}
}
