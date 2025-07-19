#include <bits/stdc++.h>
#include <queue>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; cin >> N >> M;
		vector<vector<int>> adj(N);
		vector<int> deg(N);
		for (int i = 0; i < M; ++i) {
			int a, b; cin >> a >> b; a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
			deg[a]++;
			deg[b]++;
		}
		vector<int> dist(N, 1e9);
		{
			struct Item {
				int v; int d;
				bool operator<(const Item &other) const {
					return d < other.d;
				}
			};
			priority_queue<Item> pq;
			dist[0] = 0;
			pq.push({0, 0});
			while (!pq.empty()) {
				auto [v, d] = pq.top(); pq.pop();
				if (d != dist[v]) continue;
				for (int p = 0; p < deg[v]; ++p) {
					int to = adj[v][(d + p) % deg[v]];
					if (d + p + 1 < dist[to]) {
						dist[to] = d + p + 1;
						pq.emplace(to, dist[to]);
					}
				}
			}
		}

		vector<vector<int>> dp(N, vector<int>(N, 1e9));
		{
			struct Item {
				int v, d, mn_wait;
				bool operator<(const Item &other) const { 
					return mn_wait < other.mn_wait;
				}
			};
			deque<Item> pq;
			dp[0][0] = 0;
			pq.push_back({0, 0, 0});
			while (!pq.empty()) {
				auto [v, d, mn_wait] = pq.front(); pq.pop_front();
				int p = d - dist[v];
				if (mn_wait != dp[v][p]) continue;
				int to = adj[v][d % deg[v]];
				if (d + 1 >= dist[to] && d + 1 < dist[to] + N) {
					int np = (d + 1) - dist[to];
					if (mn_wait < dp[to][np]) {
						dp[to][np] = mn_wait;
						pq.push_front({to, d + 1, dp[to][np]});
					}
				}
				if (p != N - 1) {
					int np = p + 1;
					if (mn_wait + 1 < dp[v][np]) {
						dp[v][np] = mn_wait + 1;
						pq.push_back({v, d + 1, dp[v][np]});
					}
				}
			}
		}
		int tot_dist = dist[N - 1];
		int mn_wait = dp[N - 1][0];
		cout << tot_dist << " " << mn_wait << '\n';
	}();
}
