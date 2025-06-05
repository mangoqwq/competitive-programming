#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

template <typename T>
struct Fenwick {
	std::vector<T> v;
	Fenwick(int N) { v.resize(N + 1, 1e9); }
	void ins(int i, T val) {
		for (++i; i < (int)v.size(); i += i & -i) v[i] = min(v[i], val);
	}
	T qry(int i) {
		T ret(1e9);
		for (++i; i; i -= i & -i) ret = min(ret, v[i]);
		return ret;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	const int MN = 1e6;
	int N, M; cin >> N >> M;
	struct Point { int x, y, id; };
	vector<Point> pts(N + M);
	for (int i = 0; i < N + M; ++i) {
		int x, y; cin >> x >> y; x--; y--;
		pts[i] = {x, y, i};
	}

	vector<int> ans(M, 1e9);
	auto calc = [&]() -> void {
		ranges::sort(pts, [&](Point a, Point b) {
			return tie(a.x, a.y) < tie(b.x, b.y);
		});
		Fenwick<int> bit(MN);
		for (auto &[x, y, id] : pts) {
			if (id < N) bit.ins(y, - (x + y));
			else {
				ans[id - N] = min(ans[id - N], x + y + bit.qry(y));
			}
		}
	};
	for (int i = 0; i < 4; ++i) {
		calc();
		for (auto &[x, y, id] : pts) {
			tie(x, y) = pair<int, int>{y, MN - x - 1};
		}
	}
	for (int i = 0; i < M; ++i) {
		cout << ans[i] << (i == M - 1 ? '\n' : ' ');
	}
}
