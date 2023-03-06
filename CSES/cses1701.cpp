#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [](){
		int N; cin >> N;
		vector<vector<int>> adj1(N);
		vector<vector<int>> adj2(N);
		for (int i = 0; i < N-1; ++i){
			int a, b; cin >> a >> b;
			a--, b--;
			adj1[a].push_back(b);
			adj1[b].push_back(a);
		}
		for (int i = 0; i < N-1; ++i){
			int a, b; cin >> a >> b;
			a--, b--;
			adj2[a].push_back(b);
			adj2[b].push_back(a);
		}

		const ll random = rand() ^ ((ll)rand() << 31);
		auto scramble = [&](ll x){
			x ^= random;
			x ^= x << 13;
			x ^= x >> 6;
			x ^= x << 17;
			x ^= random;
			return x;
		}; 

		auto dfs = [&](auto self, int v, int p, const auto &adj) -> ll {
			ll ret = 1;
			for (int to : adj[v]){
				if (to == p) continue;
				ret += scramble(self(self, to, v, adj));
			}
			return ret;
		};

		vector<int> sz(N);
		auto get_sz = [&](auto self, int v, int p, const auto &adj) -> int {
			sz[v] = 1;
			for (int to : adj[v]){
				if (to == p) continue;
				sz[v] += self(self, to, v, adj);
			}
			return sz[v];
		};

		auto locate = [&](auto self, int v, int p, int src, const auto &adj) -> int {
			for (int to : adj[v]){
				if (to == p) continue;
				if (sz[to] * 2 > sz[src]) return self(self, to, v, src, adj);
			}
			return v;
		};

		auto centroids = [&](const auto &adj) -> vector<int> {
			get_sz(get_sz, 0, 0, adj);
			int rt = locate(locate, 0, 0, 0, adj);
			vector<int> ret = {rt};
			for (int to : adj[rt]){
				if ((N - sz[to]) * 2 > N) continue;
				bool good = 1;
				for (int ch : adj[to]){
					if (ch == rt) continue;
					good &= sz[ch] * 2 <= N;
				}
				if (good) ret.push_back(to);
			}
			return ret;
		};

		bool ans = [&]() -> bool {
			for (int c1 : centroids(adj1)){
				for (int c2 : centroids(adj2)){
					ll h1 = dfs(dfs, c1, c1, adj1);
					ll h2 = dfs(dfs, c2, c2, adj2);
					if (h1 == h2) return 1;
				}
			}
			return 0;
		}();

		cout << (ans ? "YES" : "NO") << '\n';
	}();
}
