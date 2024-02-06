#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

mt19937 gen;
ll randint(ll l, ll r){ return uniform_int_distribution<ll>(l, r)(gen); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; cin >> N >> M;
		vector<pair<int, int>> edges;
		for (int i = 0; i < M; ++i) {
			int a, b; cin >> a >> b; a--, b--;
			edges.push_back({a, b});
		}

		const int T = 40;
		auto testConnected = [&](int u, int v) -> int {
			u++, v++;
			for (int i = 0; i < T; ++i) {
				int y = (randint(0, 1) ? u : v);
				cout << "? " << y << '\n';
				cout.flush();
				int ret; cin >> ret;
				if (ret == 0) return 0;
			}
			return 1;
		};
		auto enable = [&](int x) -> void {
			cout << "+ " << ++x << '\n';
			cout.flush();
		};
		auto disable = [&](int x) -> void {
			cout << "- " << ++x << '\n';
			cout.flush();
		};

		vector<int> tree;
		auto formSpanningTree = [&]() {
			for (int i = 0; i < M; ++i) {
				auto [u, v] = edges[i];
				disable(i);
				if (!testConnected(u, v)) {
					tree.push_back(i);
					enable(i);
				}
			}
		};
		formSpanningTree();

		struct Edge { int to, id; };
		vector<vector<Edge>> adj(N);
		for (int i : tree) {
			auto [u, v] = edges[i];
			adj[u].push_back({v, i});
			adj[v].push_back({u, i});
		}
		auto getPath = [&](int src, int dest) -> vector<int> {
			vector<int> path;
			bool found = 0;
			auto dfs = [&](auto self, int v, int p) -> void {
				if (v == dest) {
					found = 1;
					return;
				}
				for (auto [to, id] : adj[v]) {
					if (to == p) continue;
					path.push_back(id);
					self(self, to, v);
					if (found) return;
					path.pop_back();
				}
			};
			dfs(dfs, src, src);
			return path;
		};

		vector<int> ans(M);
		for (int i : tree) ans[i] = 1;

		for (int i = 0; i < M; ++i) {
			if (ans[i]) continue;
			auto [u, v] = edges[i];
			auto path = getPath(u, v);
			disable(path[0]);
			enable(i);
			if (testConnected(u, v)) ans[i] = 1;
			disable(i);
			enable(path[0]);
		}

		cout << "! ";
		for (int i = 0; i < M; ++i) {
			cout << ans[i] << (i == M-1 ? '\n' : ' ');
		}
		cout.flush();
		int result; cin >> result;
		if (result == 0) exit(0);
	}();
}
