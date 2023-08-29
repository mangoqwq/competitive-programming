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
	int N, L, R; cin >> N >> L >> R;
	struct Edge { int to, t; };
	const int MN = 2e5;
	vector<vector<Edge>> adj(MN);
	for (int i = 0; i < N; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back({b, i});
	}

	for (int i = 0; i < MN; ++i) {
		reverse(adj[i].begin(), adj[i].end());
	}

	vector<int> ans;
	const int lim = 1e6;
	auto go = [&](auto self, int v, int ct) -> void {
		if (ans.size() == lim) return;
		ans.push_back(v);
		for (auto [to, t] : adj[v]) {
			if (t < ct) return;
			self(self, to, t);
		}
	};
	go(go, 0, 0);
	for (int i = L; i < R; ++i) {
		cout << ans[i % ans.size()] << (i == R-1 ? '\n' : ' ');
	}
}
