#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	const int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
	const int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
	int N; std::cin >> N;
	std::vector<std::vector<int>> dist(N, std::vector<int>(N, 1e9));
	auto in = [&](int x, int y) {
		return x >= 0 && y >= 0 && x < N && y < N;
	};
	std::queue<std::pair<int, int>> q;
	dist[0][0] = 0;
	q.emplace(0, 0);
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int dir = 0; dir < 8; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (!in(nx, ny)) continue;
			if (dist[x][y] + 1 < dist[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1;
				q.emplace(nx, ny);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << dist[i][j] << (j == N - 1 ? '\n' : ' ');
		}
	}
}
