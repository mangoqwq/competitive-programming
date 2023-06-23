#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

struct DsuWithRollback {
	vector<int> p, sz;
	vector<pair<int, int>> hist;
	int components;
	DsuWithRollback(int N) : p(N), sz(N, 1), components(N) {
		iota(p.begin(), p.end(), 0);
	}
	void undo() {
		assert(!hist.empty());
		auto [a, b] = hist.back();
		hist.pop_back();
		if (a != -1) {
			p[b] = b;
			sz[a] -= sz[b];
			components++;
		}
	}
	int root(int x) {
		return p[x] == x ? x : root(p[x]);
	}
	void unite(int a, int b) {
		a = root(a), b = root(b);
		if (a == b) {
			hist.push_back({-1, -1});
			return;
		}
		if (sz[b] > sz[a]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		hist.push_back({a, b});
		components--;
	}
};

/*
https://cp-algorithms.com/data_structures/deleting_in_log_n.html
can be solved in O(N logN log(M+K))
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, Q; cin >> N >> M >> Q;
	Q += M;
	struct Op { int c, a, b; };
	vector<Op> ops;
	for (int i = 0; i < Q; ++i) {
		int c = 1, a, b;
		if (i >= M) cin >> c;
		cin >> a >> b;
		a--, b--;
		if (b > a) swap(a, b);
		ops.push_back({c, a, b});
	}

	using pii = pair<int, int>;
	vector<vector<pii>> st(2*Q);
	auto insert = [&](auto self, int v, int l, int r, int ql, int qr, pii edge) -> void {
		if (l >= qr || r <= ql) return;
		else if (l >= ql && r <= qr) st[v].push_back(edge);
		else {
			int m = (l+r)>>1;
			int lc = v + 1;
			int rc = v + 2*(m - l);
			self(self, lc, l, m, ql, qr, edge);
			self(self, rc, m, r, ql, qr, edge);
		}
	};

	map<pii, int> mp;
	for (int i = 0; i < Q; ++i) {
		auto [c, a, b] = ops[i];
		if (c == 1) {
			mp[{a, b}] = i;
		}
		else {
			int l = mp[{a, b}], r = i;
			mp.erase({a, b});
			insert(insert, 0, 0, Q, l, r, {a, b});
		}
	}
	for (auto [edge, l] : mp) {
		insert(insert, 0, 0, Q, l, Q, edge);
	}

	vector<int> ans(Q);
	DsuWithRollback dsu(N);
	auto dfs = [&](auto self, int v, int l, int r) -> void {
		for (auto [a, b] : st[v]) {
			dsu.unite(a, b);
		}
		if (l+1 == r) ans[l] = dsu.components;
		else {
			int m = (l+r)>>1;
			int lc = v + 1;
			int rc = v + 2*(m - l);
			self(self, lc, l, m);
			self(self, rc, m, r);
		}
		for (auto [a, b] : st[v]) {
			dsu.undo();
		}
	};
	dfs(dfs, 0, 0, Q);

	for (int i = M-1; i < Q; ++i) {
		cout << ans[i] << (i == Q-1 ? '\n' : ' ');
	}
}
