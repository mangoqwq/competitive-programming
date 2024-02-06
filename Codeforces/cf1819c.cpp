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
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> dist(N), lst(N);
	auto dfs = [&](auto self, int v, int p) -> void {
		for (int to : adj[v]) {
			if (to == p) continue;
			dist[to] = dist[v] + 1;
			lst[to] = v;
			self(self, to, v);
		}
	};
	dfs(dfs, 0, 0);
	int u = max_element(dist.begin(), dist.end()) - dist.begin();
	dfs(dfs, u, u);
	int v = max_element(dist.begin(), dist.end()) - dist.begin();

	vector<int> path = {v};
	while (path.back() != u) {
		path.push_back(lst[path.back()]);
	}

	vector<int> ans;
	for (int i = 0; i < path.size(); ++i) {
		if (i % 2 == 0) ans.push_back(path[i]);
		else {
			for (int to : adj[path[i]]) {
				if (i != 0 && to == path[i-1]) continue;
				if (i != path.size()-1 && to == path[i+1]) continue;
				ans.push_back(to);
			}
		}
	}
	for (int i = path.size()-1; i >= 0; --i) {
		if (i % 2 == 1) ans.push_back(path[i]);
		else {
			for (int to : adj[path[i]]) {
				if (i != 0 && to == path[i-1]) continue;
				if (i != path.size()-1 && to == path[i+1]) continue;
				ans.push_back(to);
			}
		}
	}

	if (ans.size() != N) cout << "No" << '\n';
	else {
		cout << "Yes" << '\n';
		for (int i = 0; i < N; ++i) {
			cout << ans[i]+1 << (i == N-1 ? '\n' : ' ');
		}
	}
}
