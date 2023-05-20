#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

template <typename T>
struct Fenwick {
	vector<T> v;
	Fenwick(int N) { v.resize(N + 1); }
	void ins(int i, T val) {
		for (++i; i < v.size(); i += i & -i) v[i] += val;
	}
	T qry(int i) {
		T ret(0);
		for (++i; i; i -= i & -i) ret += v[i];
		return ret;
	}
	// [l, r)
	T qry(int l, int r) { return qry(r - 1) - qry(l - 1); }
};

/*
binary search for the instruction that causes an intersection
to check if some prefix of instructions causes an intersection,
we write the path as a collection of vertical and horizontal lines
and check if there is an intersection by doing line sweep

after we know which instruction causes an intersection,
we can find when this intersection happens by brute force

O(NlogNlogN + X)

implementation so long... there is probably a better way
*/

map<char, pair<int, int>> dirs = {
	{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	ll totd = 0;
	struct Move { char dir; int d; };
	vector<Move> moves(N);
	vector<pair<ll, ll>> spts(N), tpts(N);
	ll x = 0, y = 0;
	for (int i = 0; i < N; ++i) {
		auto &[dir, d] = moves[i];
		cin >> dir >> d;
		totd += d;

		auto [dx, dy] = dirs[dir];
		ll sx, sy;
		if (i == 0) sx = sy = 0;
		else sx = x + dx, sy = y + dy;
		ll tx = x + d * dx, ty = y + d * dy;
		spts[i] = pair<ll, ll>(sx, sy);
		tpts[i] = pair<ll, ll>(tx, ty);
		tie(x, y) = tie(tx, ty);
	}

	vector<ll> comp;
	for (auto [x, y] : spts) {
		comp.push_back(y);
	}
	for (auto [x, y] : tpts) {
		comp.push_back(y);
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for (auto &[x, y] : spts) {
		y = lower_bound(comp.begin(), comp.end(), y) - comp.begin();
	}
	for (auto &[x, y] : tpts) {
		y = lower_bound(comp.begin(), comp.end(), y) - comp.begin();
	}

	ll lo = 1, hi = N;
	while (lo < hi) {
		ll mi = (lo + hi + 1) >> 1;

		struct Event {
			// horizontal lines c=0, vertical lines c=1
			int c; ll x, l, r;
			bool operator< (const Event &other) const {
				return tie(x, c) < tie(other.x, other.c);
			}
		};
		struct Seg {
			ll l, r;
			bool operator< (const Seg &other) const {
				return l < other.l; 
			}
		};
		unordered_map<ll, vector<Seg>> hori, vert;
		vector<Event> eves;
		for (int i = 0; i < mi; ++i) {
			auto [sx, sy] = spts[i];
			auto [tx, ty] = tpts[i];

			if (moves[i].dir == 'U' || moves[i].dir == 'D') { // vertical line
				vert[tx].push_back({min(sy, ty), max(sy,ty)+1});
				eves.push_back({1, tx, min(sy, ty), max(sy, ty)+1});
			}
			else { // horizontal line
				hori[ty].push_back({min(sx, tx), max(sx, tx)+1});
				eves.push_back({0, min(sx, tx), ty, 1});
				eves.push_back({0, max(sx, tx)+1, ty, -1});
			}
		}

		bool intersect = [&]() -> bool {
			Fenwick<int> bit(comp.size());
			// check hori-vert intersections
			sort(eves.begin(), eves.end());
			for (auto &[c, x, l, r] : eves) {
				if (c == 0) {
					bit.ins(l, r);
				}
				else {
					if (bit.qry(l, r)) return 1;
				}
			}

			// check hori-hori and vert-vert intersections
			for (auto &[x, segs] : hori) {
				sort(segs.begin(), segs.end());
				ll lst = -1e18;
				for (auto [l, r] : segs) {
					if (l < lst) return 1;
					lst = r;
				}
			}
			for (auto &[x, segs] : vert) {
				sort(segs.begin(), segs.end());
				ll lst = -1e18;
				for (auto [l, r] : segs) {
					if (l < lst) return 1;
					lst = r;
				}
			}
			return 0;
		}();

		if (intersect == 0) lo = mi;
		else hi = mi - 1;
	}

	debug(lo);

	if (lo == N) {
		cout << totd << '\n';
		return 0;
	}

	ll ans = 0;
	x = y = 0;
	unordered_set<ll> bad;

	ll lpos, lvert;
	for (int i = 0; i < lo; ++i) {
		auto [dir, d] = moves[i];
		auto [dx, dy] = dirs[dir];
		x = x + d * dx, y = y + d * dy;
	}
	if (moves[lo].dir == 'U' || moves[lo].dir == 'D') {
		lvert = 1;
		lpos = x;
	}
	else {
		lvert = 0;
		lpos = y;
	}

	x = 0, y = 0;
	for (int i = 0; i < lo; ++i) {
		auto [dir, d] = moves[i];
		ans += d;
		auto [dx, dy] = dirs[dir];
		ll tx = x + d * dx, ty = y + d * dy;
		if (lvert) {
			// last line is vertical
			if (tx == x) {
				// current line is vertical
				if (tx == lpos) {
					bad.insert(y);
					bad.insert(ty);
				}
			}
			else {
				// current line is horizontal
				if (min(x, tx) <= lpos && lpos <= max(x, tx)) bad.insert(y);
			}
		}
		else {
			// last line is horizontal
			if (ty == y) {
				// current line is horizontal
				if (ty == lpos) {
					bad.insert(x);
					bad.insert(tx);
				}
			}
			else {
				// current line is vertical
				if (min(y, ty) <= lpos && lpos <= max(y, ty)) bad.insert(x);
			}
		}
		tie(x, y) = tie(tx, ty);
	}

	debug(ans);
	debug(bad);
	debug(lvert);
	debug(moves[lo].dir, moves[lo].d);
	debug(moves[lo-1].dir, moves[lo-1].d);

	if (moves[lo].dir == 'U' && moves[lo-1].dir == 'D' || 
			moves[lo].dir == 'D' && moves[lo-1].dir == 'U' ||
			moves[lo].dir == 'L' && moves[lo-1].dir == 'R' ||
			moves[lo].dir == 'R' && moves[lo-1].dir == 'L') {
		cout << ans << '\n';
		return 0;
	}

	auto [dir, d] = moves[lo];
	auto [dx, dy] = dirs[dir];
	for (int i = 0; i < d; ++i) {
		ans++;
		x += dx, y += dy;
		debug(i);
		if (lvert && bad.count(y)) break;
		if (!lvert && bad.count(x)) break;
	}
	cout << ans << '\n';
}
