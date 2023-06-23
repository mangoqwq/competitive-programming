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
	vector<vector<int>> adj(N);
	vector<vector<int>> uni(N);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		uni[a].push_back(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	vector<int> vis(N);
	auto dfs = [&](auto self, int v, vector<int> &cc) -> void {
		vis[v] = 1;
		cc.push_back(v);
		for (int to : adj[v]) {
			if (vis[to]) continue;
			self(self, to, cc);
		}
	};

	vector<int> deg(N);
	auto isdag = [&](vector<int> &cc) {
		for (int v : cc) {
			for (int to : uni[v]) {
				deg[to]++;
			}
		}
		queue<int> q;
		for (int v : cc) {
			if (deg[v] == 0) q.push(v);
		}
		int vis = 0;
		while (!q.empty()) {
			vis++;
			int v = q.front(); q.pop();
			for (int to : uni[v]) {
				deg[to]--;
				if (deg[to] == 0) q.push(to);
			}
		}
		return vis == cc.size();
	};
 
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (vis[i]) continue;
		vector<int> cc;
		dfs(dfs, i, cc);
		if (isdag(cc)) ans += cc.size()-1;
		else ans += cc.size();
	}
	cout << ans << '\n';
}
