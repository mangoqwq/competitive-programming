#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N, M; cin >> N >> M;
		vector<int> c(N);
		for (int i = 0; i < N; ++i){
			cin >> c[i];
		}

		vector<vector<int>> adj(N);
		for (int i = 0; i < M; ++i){
			int a, b; cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		auto bfs = [&]() -> int {
			vector<vector<int>> dist(N, vector<int>(N, 1e9));
			dist[0][N-1] = 0;
			using pii = pair<int, int>;
			queue<pii> q;
			q.push({0,N-1});
			while (!q.empty()){
				auto [u, v] = q.front(); q.pop();
				for (int to1 : adj[u]) for (int to2 : adj[v]){
					if (c[to1] == c[to2]) continue;
					if (dist[u][v] + 1 < dist[to1][to2]){
						dist[to1][to2] = dist[u][v] + 1;
						q.push({to1, to2});
					}
				}
			}
			return dist[N-1][0];
		};

		int d = bfs();
		if (d == 1e9) cout << -1 << '\n';
		else cout << d << '\n';
	}();
}
