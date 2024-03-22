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
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		vector<vector<int>> adj(N);
		for (int i = 0; i < N-1; ++i) {
			int a, b; cin >> a >> b; a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> dist(N);
		vector<int> from(N);
		int far = 0;
		auto dfs = [&](auto self, int v, int p) -> void {
			if (dist[v] > dist[far]) far = v;
			for (int to : adj[v]) {
				if (to == p) continue;
				dist[to] = dist[v] + 1;
				from[to] = v;
				self(self, to, v);
			}
		};
		dfs(dfs, 0, 0);
		int a = far;
		dist[a] = 0;
		dfs(dfs, a, a);
		int b = far;
		vector<int> path;
		for (int i = b; i != a; i = from[i]) {
			path.push_back(i);
		}
		path.push_back(a);

		int M = path.size();
		if (M % 2 == 1) {
			int rt = path[M/2];
			cout << M/2 + 1 << '\n';
			for (int i = M/2; i >= 0; --i) {
				cout << rt+1 << " " << i << '\n';
			}
		}
		else {
			int rt = path[M/2];
			if (M % 4 == 0) {
				auto attempt = [&](map<int, set<int>> moves) -> bool {
					vector<int> black(N);
					for (auto [rt, ds] : moves) {
						dist[rt] = 0;
						dfs(dfs, rt, rt);
						for (int i = 0; i < N; ++i) {
							if (ds.count(dist[i])) black[i] = 1;
						}
					}
					debug(moves, black);
					return *min_element(black.begin(), black.end()) == 1;
				};
				for (int i = 1; i < M-1; ++i) {
					int r1 = path[i]; int d1 = (i <= M/2-1 ? i : M-1 - i);
					map<int, set<int>> moves;
					moves[r1].insert(d1);
					deque<int> dq_odd, dq_even;
					for (int j = 0; j < M; ++j) {
						if (j == i-d1 || j == i+d1) continue;
						if (j % 2) dq_odd.push_back(j);
						else dq_even.push_back(j);
					}
					auto process = [&](deque<int> dq) {
						while (!dq.empty()) {
							debug(dq);
							int c = dq.front(); dq.pop_front();
							int d = dq.back(); dq.pop_back();
							int r = (c+d) / 2; int dis = r - c;
							moves[path[r]].insert(dis);
						}
					};
					process(dq_odd);
					process(dq_even);
					if (attempt(moves)) {
						cout << M/2 << '\n';
						for (auto [rt, ds] : moves) {
							for (int dis : ds) {
								cout << rt+1 << " " << dis << '\n';
							}
						}
						return;
					}
				}
				cout << M/2+1 << '\n';
				for (int i = M/2; i >= 0; --i) {
					cout << rt+1 << " " << i << '\n';
				}
			}
			else {
				cout << M/2 + 1 << '\n';
				for (int i = M/2; i >= 0; --i) {
					cout << rt+1 << " " << i << '\n';
				}
			}
		}
	}();
}
