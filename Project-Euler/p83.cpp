#include <bits/stdc++.h>
#include <queue>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N = 80;
	string line;
	vector<vector<int>> mat;
	while (getline(cin, line)) {
		istringstream iss(line);
		mat.push_back({});
		for (int i = 0; i < N; ++i) {
			int x; char c; iss >> x >> c;
			mat.back().push_back(x);
		}
	}

	vector<vector<int>> dist(N, vector<int>(N, 1e9));
	dist[0][0] = mat[0][0];
	struct Item {
		int d, x, y;
		bool operator<(const Item &other) const {
			return d > other.d;
		}
	};
	priority_queue<Item> pq;
	pq.push({mat[0][0], 0, 0});
	while (!pq.empty()) {
		auto [d, x, y] = pq.top(); pq.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (dist[nx][ny] > d + mat[nx][ny]) {
				dist[nx][ny] = d + mat[nx][ny];
				pq.push({dist[nx][ny], nx, ny});
			}
		}
	}
	cout << dist[N-1][N-1] << '\n';
}

