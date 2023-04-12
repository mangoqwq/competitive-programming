#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N, M; cin >> N >> M;
		vector<vector<int>> adj(N);
		for (int i = 0; i < M; ++i){
			int a, b; cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int k = 0;
		bool right_size = [&]() -> bool {
			for (k = 3; k * k <= N; ++k){
				if (k * k == N){
					return M == k*(k+1);
				}
			}
			return 0;
		}();

		if (!right_size){
			cout << "NO" << '\n';
			return;
		}

		set<int> center;
		for (int i = 0; i < N; ++i){
			if (adj[i].size() == 4) center.insert(i);
		}

		bool center_good = [&]() -> bool {
			if (center.size() != k) return 0;

			set<int> vis;
			int src = *center.begin();

			auto dfs = [&](auto self, int v, int p) -> bool {
				if (v != p && v == src){
					return vis == center;
				}
				vis.insert(v);
				for (int to : adj[v]){
					if (to == p || !center.count(to)) continue;
					return self(self, to, v);
				}
				return 0;
			};
			return dfs(dfs, src, src);
		}();

		if (!center_good){
			cout << "NO" << '\n';
			return;
		}

		bool outers_good = [&]() -> bool {
			for (int src : center){
				int cnt = 0;
				auto dfs = [&](auto self, int v, int p) -> bool {
					if (v != p && v == src){
						return cnt == k;
					}
					cnt++;
					for (int to : adj[v]){
						if (to == p || (to != src && center.count(to))) continue;
						return self(self, to, v);
					}
					return 0;
				};
				if (!dfs(dfs, src, src)) return 0;
			}
			return 1;
		}();

		if (!outers_good){
			cout << "NO" << '\n';
			return;
		}

		cout << "YES" << '\n';
	}();
}
