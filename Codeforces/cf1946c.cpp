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
	int T; cin >> T;
	while (T--) [&]() {
		int N, K; cin >> N >> K;
		vector<vector<int>> adj(N);
		for (int i = 0; i < N-1; ++i) {
			int a, b; cin >> a >> b; a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		auto dfs = [&](auto self, int v, int p, int req, int &comp) -> int {
			int sz = 1;
			for (int to : adj[v]) {
				if (to == p) continue;
				sz += self(self, to, v, req, comp);
			}
			if (sz >= req) {
				comp++;
				return 0;
			}
			return sz;
		};
		int lo = 1, hi = N;
		while (lo < hi) {
			int mi = (lo + hi + 1) >> 1;
			int comp = 0;
			dfs(dfs, 0, 0, mi, comp);
			if (comp >= K+1) lo = mi;
			else hi = mi - 1;
		}
		cout << lo << '\n';
	}();
}
