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

	vector<int> ea(M), eb(M);
	struct Edge{ int to, id; };
	vector<vector<Edge>> adj(N);
	int ans = 1e9;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		ea[i] = a, eb[i] = b;
		if (a == b) ans = 1;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}

	auto attempt = [&](int rt) -> void {
		vector<int> dist(N, 1e9);
		vector<int> used(M, 0);

		queue<int> q;
		q.push(rt);
		dist[rt] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto [to, id] : adj[v]) {
				if (dist[to] == 1e9) {
					used[id] = 1;
					dist[to] = dist[v] + 1;
					q.push(to);
				}
			}
		}

		for (int i = 0; i < M; ++i) {
			if (used[i]) continue;
			ans = min(ans, dist[ea[i]] + dist[eb[i]] + 1);
		}
	};

	for (int i = 0; i < N; ++i) {
		attempt(i);
	}
	if (ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';

}
