#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector<vector<int>> adj(N);
		for (int i = 1; i < N; ++i){
			int p; cin >> p;
			p--;
			adj[p].push_back(i);
		}
		vector<int> l(N), r(N);
		for (int i = 0; i < N; ++i){
			cin >> l[i] >> r[i];
		}

		int ans = 0;
		auto dfs = [&](auto self, int v) -> ll {
			ll val = 0;
			for (int to : adj[v]){
				val += self(self, to);
			}
			if (val < l[v]) val = r[v], ans++;
			return min(val, (ll)r[v]);
		};
		dfs(dfs, 0);
		cout << ans << '\n';
	}
}
