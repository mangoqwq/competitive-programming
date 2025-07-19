#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N = 1e5;
	vector<vector<int>> polygonal(N, vector<int>(6));
	auto upd = [&](ll n, int i) { if (n < N) polygonal[n][i] = 1; };
	for (ll n = 0; n < N; ++n) {
		upd(n * (n+1) / 2, 0);
		upd(n * n, 1);
		upd(n * (3 * n - 1) / 2, 2);
		upd(n * (2 * n - 1), 3);
		upd(n * (5 * n - 3) / 2, 4);
		upd(n * (3 * n - 2), 5);
	}
	for (int src = 10; src < 100; ++src) {
		vector<vector<int>> vis(N, vector<int>(1 << 6));
		vector<int> path = {src};
		auto dfs = [&](auto self, int v, int msk) -> bool {
			vis[v][msk] = 1;
			if (__builtin_popcount(msk) == 5) {
				int i = __builtin_ctz(~msk);
				if (polygonal[v * 100 + src][i]) {
					return 1;
				}
			}
			for (int i = 0; i < 6; ++i) {
				int nmsk = (1 << i) | msk;
				if (msk == nmsk) continue;
				for (int to = 10; to < 100; ++to) {
					if (!polygonal[v * 100 + to][i]) continue;
					if (vis[to][nmsk]) continue;
					path.push_back(to);
					if (self(self, to, nmsk)) return 1;
					path.pop_back();
				}
			}
			return 0;
		};
		if (dfs(dfs, src, 0)) {
			for (int i = 0; i < 6; ++i) {
				int num = path[i] * 100 + path[(i+1)%6];
				for (int j = 0; j < 6; ++j) {
					cout << polygonal[num][j];
				}
				cout << '\n';
			}
			int ans = 101 * accumulate(path.begin(), path.end(), 0);
			cout << ans << '\n';
			break;
		}
	}
}
