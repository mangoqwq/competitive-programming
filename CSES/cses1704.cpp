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

	int rt = 0;
	while (adj[rt].size() == 1) rt++;

	using pii = pair<int, int>;
	vector<pii> edges;
	auto dfs = [&](auto self, int v, int p) -> vector<int> {
		int leaf = 1;
		int two = -1;
		vector<int> one;
		for (int to : adj[v]) {
			if (to == p) continue;
			leaf = 0;
			auto vec = self(self, to, v);
			int l = vec[0];
			if (two != -1) {
				edges.push_back({l, two});
				two = -1;
			}
			else one.push_back(l);
			if (vec.size() == 2) {
				two = vec[1];
			}
		}
		if (leaf) {
			return {v};
		}
		else {
			while ((two != -1 && one.size() >= 2) || one.size() > 2) {
				int a = one.back(); one.pop_back();
				int b = one.back(); one.pop_back();
				edges.push_back({a, b});
			}
			if (two != -1) one.push_back(two);
			return one;
		}
	};
	auto v = dfs(dfs, rt, rt);
	if (v.size() == 2) {
		edges.push_back({v[0], v[1]});
	}
	else if (v.size() == 1) {
		edges.push_back({v[0], rt});
	}

	cout << edges.size() << '\n';
	for (auto [a, b] : edges) {
		cout << a+1 << " " << b+1 << '\n';
	}
}
