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
	int N, M; cin >> N >> M;
	vector<vector<int>> a(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c; cin >> c;
			a[i][j] = c == '#';
		}
	}

	const int dx[] = {-1, 0, 1, 0};
	const int dy[] = {0, 1, 0, -1};

	auto in = [&](int x, int y) -> int {
		return x >= 0 && x < N && y >= 0 && y < M;
	};

	vector<vector<int>> vis(N, vector<int>(M));
	auto calc = [&](int x, int y) -> ll {
		int r = 0, w = 0;
		auto go = [&](auto self, int x, int y) -> void {
			if ((x + y) % 2 == 0) r++;
			else w++;
			vis[x][y] = 1;
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (in(nx, ny) && a[nx][ny] != a[x][y]) {
					if (!vis[nx][ny]) self(self, nx, ny);
				}
			}
		};
		go(go, x, y);
		return 1LL * r * w;
	};

	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!vis[i][j]) ans += calc(i, j);
		}
	}
	cout << ans << '\n';
}
