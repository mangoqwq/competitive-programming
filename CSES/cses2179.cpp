#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
essentially the problem boils down to pairing edges that are incident to a common vertex
build dfs tree, pair back edges with back edges
if there are left over back edges, pair with tree edges
by construction every connected graph with an even number of
edges can be paired
note that there could be multiple components in the graph
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;

	struct Edge{ int to, id; };
	vector<vector<Edge>> adj(N);
	vector<int> edges;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
		edges.push_back(a^b);
	}

	vector<int> owner(M, -1);
	vector<int> in(M);
	int T = 0;
	auto dfs = [&](auto self, int v, int p) -> bool {
		in[v] = ++T;
		vector<int> ava;
		for (auto [to, id] : adj[v]) {
			if (id == p) continue;
			if (in[to] && in[to] < in[v]) {
				ava.push_back(id);
			}
			else if (!in[to]) {
				if (self(self, to, id)) {
					ava.push_back(id);
				}
			}
		}
		while (ava.size() >= 2) {
			int a = ava.back(); ava.pop_back();
			int b = ava.back(); ava.pop_back();
			owner[a] = v;
			owner[b] = v;
		}
		if (p != -1 && ava.size() == 1) {
			int a = ava.back(); ava.pop_back();
			int b = p;
			owner[a] = v;
			owner[b] = v;
			return 0;
		}
		return 1;
	};


	for (int i = 0; i < N; ++i) {
		if (!in[i]) dfs(dfs, i, -1);
	}

	if (count(owner.begin(), owner.end(), -1)) {
		cout << "IMPOSSIBLE" << '\n';
		return 0;
	}
	for (int i = 0; i < M; ++i) {
		cout << owner[i]+1 << " " << (edges[i] ^ owner[i])+1 << '\n';
	}
}
