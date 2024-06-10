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
		int N; cin >> N;
		vector<vector<int>> adj(N);
		for (int i = 0; i < N-1; ++i) {
			int a, b; cin >> a >> b; a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		vector<int> black(N), white(N);
		auto dfs = [&](auto self, int v, int p) -> void {
			black[v] = 1;
			for (int to : adj[v]) {
				if (to == p) continue;
				self(self, to, v);
				black[v] += white[to];
				white[v] += black[to];
			}
			white[v] = min(white[v], black[v]);
		};
		dfs(dfs, 0, 0);

		int ans = 0;
		auto reroot = [&](auto self, int v, int p, int b, int w) -> void {
			int sumb = b, sumw = w;
			for (int to : adj[v]) {
				if (to == p) continue;
				sumw += white[to];
				sumb += black[to];
			}
			ans = max(ans, N - 1 - sumw + (adj[v].size() == 1));
			for (int to : adj[v]) {
				if (to == p) continue;
				int newb = sumw + 1 - white[to];
				int neww = min(newb, sumb - black[to]);
				self(self, to, v, newb, neww);
			}
		};
		reroot(reroot, 0, 0, 0, 0);
		cout << ans << '\n';
	}();
}
