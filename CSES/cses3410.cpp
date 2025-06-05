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
	struct Point { ll x, y; };
	auto dot = [&](Point a, Point b) {
		return a.x * b.x + a.y * b.y;
	};
	auto dist = [&](Point a, Point b) {
		return abs(a.x - b.x) + abs(a.y - b.y);
	};
	vector<Point> dirs = {
		{1, 1},
		{1, -1},
		{-1, 1},
		{-1, -1},
	};

	int N; cin >> N;
	ll ans = 0;
	vector<int> best(4, 0);

	vector<Point> p(N);
	for (int i = 0; i < N; ++i) {
		cin >> p[i].x >> p[i].y;
		for (int k = 0; k < 4; ++k) {
			int j = best[k];
			ans = max(ans, dist(p[i], p[j]));
			if (dot(dirs[k], p[i]) > dot(dirs[k], p[j])) best[k] = i;
		}
		cout << ans << '\n';
	}
}
