#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

struct LCA {
	int N, L;
	vector<vector<int>> up;
	vector<int> in, out;
	LCA (vector<vector<int>> adj, int rt) 
		: N(adj.size()), L(__lg(N)+1), up(N, vector<int>(L)), in(N), out(N) {
		int T = 0;
		auto dfs = [&](auto self, int v, int p) -> void {
			in[v] = ++T; up[v][0] = p;
			for (int i = 1; i < L; ++i) {
				up[v][i] = up[up[v][i-1]][i-1];
			}
			for (int to : adj[v]) {
				if (to == p) continue;
				self(self, to, v);
			}
			out[v] = T;
		};
		dfs(dfs, rt, rt);
	}
	bool is_anc(int a, int b) {
		return in[a] <= in[b] && out[a] >= out[b];
	}
	int lca(int a, int b) {
		if (is_anc(a, b)) return a;
		if (is_anc(b, a)) return b;
		for (int i = L-1; i >= 0; --i) {
			if (!is_anc(up[a][i], b)) a = up[a][i];
		}
		return up[a][0];
	}
	int walk(int a, int anc) {
		for (int i = L-1; i >= 0; --i) {
			debug(a, up[a][i], anc);
			if (!is_anc(up[a][i], anc)) a = up[a][i];
		}
		return a;
	}
	int climb(int a, int b, const vector<int> &has) {
		for (int i = L-1; i >= 0; --i) {
			if (is_anc(up[a][i], b)) continue;
			if (!has[up[a][i]]) a = up[a][i];
		}
		return up[a][0];
	}
};



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	vector<int> deg(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		deg[a]++, deg[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = N;
	vector<int> has(N, 1);
	vector<int> ch;
	for (int i = 0; i < N; ++i) {
		if (deg[i] <= 1) ch.push_back(i);
	}
	LCA tree(adj, 0);

	auto walk = [&](int x, int rt) {
		if (x == rt) return rt;
		if (tree.is_anc(x, rt)) return tree.walk(rt, x);
		return tree.up[x][0];
	};

	while (M--) {
		int rt; cin >> rt;
		rt--;
		if (ans == 1) {
			cout << ans << '\n';
			continue;
		}

		vector<int> nch;
		int close = rt;
		if (!has[rt]) {
			int st_root = ch[0];
			for (int x : ch) {
				st_root = tree.lca(st_root, x);
			}
			if (tree.is_anc(st_root, rt)) {
				close = tree.climb(rt, st_root, has);
			}
			else close = st_root;
			int closer = walk(close, rt);
			has[closer] = 1;
			deg[closer] = 1;
			deg[close]++;
			ans++;
			nch.push_back(closer);
		}

		for (int c : ch) {
			if (c == rt) {
				nch.push_back(c);
				continue;
			}
			int p = walk(c, rt);
			debug(c, p);
			if (c == close) continue;
			deg[c] = 0;
			has[c] = 0;
			ans--;
			deg[p]--;
			if (deg[p] == 1) nch.push_back(p);
		}
		debug(ch, nch);
		debug(deg);
		swap(nch, ch);
		cout << ans << '\n';
	}
}
