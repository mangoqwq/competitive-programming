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
		ll h1 = dfs(dfs, 0, 0, adj1);
		ll h2 = dfs(dfs, 0, 0, adj2);
		cout << (h1 == h2 ? "YES" : "NO") << '\n';
	}();
}
