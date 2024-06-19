#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

template <typename T>
struct Fenwick {
	vector<T> v;
	Fenwick(int N) { v.resize(N + 1); }
	void ins(int i, T val) {
		for (++i; i < (int)v.size(); i += i & -i) v[i] += val;
	}
	T qry(int i) {
		T ret(0);
		for (++i; i; i -= i & -i) ret += v[i];
		return ret;
	}
	T qry(int l, int r) { return qry(r - 1) - qry(l - 1); }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N; ++i) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> val(N);
	for (int i = 0; i < N; ++i) {
		cin >> val[i]; val[i]--;
	}

	vector<int> vis(N);
	Fenwick<int> bit(1000);
	int ans = 1e9;
	auto dfs = [&](auto self, int v, int d, int inv) -> void {
		inv += bit.qry(val[v] + 1, 1000);
		bit.ins(val[v], 1);
		vis[v] = 1;
		if (d >= K) ans = min(ans, inv);
		for (int to : adj[v]) {
			if (vis[to]) continue;
			self(self, to, d+1, inv);
		}
		bit.ins(val[v], -1);
		vis[v] = 0;
	};
	for (int i = 0; i < N; ++i) {
		dfs(dfs, i, 1, 0);
	}
	if (ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
}
