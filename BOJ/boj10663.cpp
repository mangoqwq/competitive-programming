#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

const int MN = 55;
int dp[MN][MN][MN][MN];
int reachable[MN][MN][MN][MN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (true) [&]() {
		int N, M; cin >> N >> M;
		if (N == 0 && M == 0) exit(0);
		vector<vector<char>> g(N, vector<char>(M));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> g[i][j];
			}
		}

		auto walkable = [&](int i, int j) -> bool {
			if (i < 0 || j < 0 || i >= N || j >= M) return 0;
			return g[i][j] != '#';
		};

		memset(reachable, 0, sizeof reachable);
		for (int sx = 0; sx < N; ++sx) for (int sy = 0; sy < M; ++sy) {
			reachable[sx][sy][sx][sy] = walkable(sx, sy);
			for (int i = sx; i < N; ++i) for (int j = sy; j < M; ++j) {
				if (reachable[sx][sy][i][j]) {
					if (walkable(i+1, j)) reachable[sx][sy][i+1][j] = 1;
					if (walkable(i, j+1)) reachable[sx][sy][i][j+1] = 1;
				}
			}
		}

		if (!reachable[0][0][N-1][M-1]) {
			cout << -1 << '\n';
			return;
		}

		auto match = [&](int i1, int j1, int i2, int j2) -> int {
			bool jewel = g[i1][j1] >= 'a' && g[i1][j1] <= 'z';
			return jewel && (g[i1][j1] - 'a' + 'A') == g[i2][j2];
		};

		memset(dp, 0, sizeof dp);
		for (int i1 = N-1; i1 >= 0; --i1) for (int j1 = M-1; j1 >= 0; --j1) {
			vector<pair<int, int>> holes;
			for (int i2 = i1; i2 < N; ++i2) for (int j2 = j1; j2 < M; ++j2) {
				auto &cur = dp[i1][j1][i2][j2];
				if (reachable[i1][j1][i1+1][j1] && reachable[i1+1][j1][i2][j2]) {
					cur = max(cur, dp[i1+1][j1][i2][j2]);
				}
				if (reachable[i1][j1][i1][j1+1] && reachable[i1][j1+1][i2][j2]) {
					cur = max(cur, dp[i1][j1+1][i2][j2]);
				}
				if (match(i1, j1, i2, j2)) {
					holes.push_back({i2, j2});
				}
				for (auto [x, y] : holes) {
					if (!reachable[i1][j1][x][y]) continue;
					if (!reachable[x][y][i2][j2]) continue;
					if (walkable(i1+1, j1) && walkable(x-1, y)) {
						cur = max(cur, 1 + dp[i1+1][j1][x-1][y] + dp[x][y][i2][j2]);
					}
					if (walkable(i1, j1+1) && walkable(x-1, y)) {
						cur = max(cur, 1 + dp[i1][j1+1][x-1][y] + dp[x][y][i2][j2]);
					}
					if (walkable(i1+1, j1) && walkable(x, y-1)) {
						cur = max(cur, 1 + dp[i1+1][j1][x][y-1] + dp[x][y][i2][j2]);
					}
					if (walkable(i1, j1+1) && walkable(x, y-1)) {
						cur = max(cur, 1 + dp[i1][j1+1][x][y-1] + dp[x][y][i2][j2]);
					}
				}
			}
		}
		cout << dp[0][0][N-1][M-1] << '\n';
	}();
}
