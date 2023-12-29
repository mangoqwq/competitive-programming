#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// Source: atcoder library
// https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html
namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
	int x = 0;
	while ((1U << x) < (unsigned int)(n)) x++;
	return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
	int x = 0;
	while (!(n & (1 << x))) x++;
	return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
	unsigned long index;
	_BitScanForward(&index, n);
	return index;
#else
	return __builtin_ctz(n);
#endif
}

}	 // namespace internal

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
					F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
 public:
	lazy_segtree() : lazy_segtree(0) {}
	explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
	explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
		log = internal::ceil_pow2(_n);
		size = 1 << log;
		d = std::vector<S>(2 * size, e());
		lz = std::vector<F>(size, id());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		return d[p];
	}

	S prod(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		if (l == r) return e();

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		S sml = e(), smr = e();
		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}

		return op(sml, smr);
	}

	S all_prod() { return d[1]; }

	void apply(int p, F f) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = mapping(f, d[p]);
		for (int i = 1; i <= log; i++) update(p >> i);
	}
	void apply(int l, int r, F f) {
		assert(0 <= l && l <= r && r <= _n);
		if (l == r) return;

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1) all_apply(l++, f);
				if (r & 1) all_apply(--r, f);
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}

		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}

	template <bool (*g)(S)>
	int max_right(int l) {
		return max_right(l, [](S x) { return g(x); });
	}
	template <class G>
	int max_right(int l, G g) {
		assert(0 <= l && l <= _n);
		assert(g(e()));
		if (l == _n) return _n;
		l += size;
		for (int i = log; i >= 1; i--) push(l >> i);
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!g(op(sm, d[l]))) {
				while (l < size) {
					push(l);
					l = (2 * l);
					if (g(op(sm, d[l]))) {
						sm = op(sm, d[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = op(sm, d[l]);
			l++;
		} while ((l & -l) != l);
		return _n;
	}

	template <bool (*g)(S)>
	int min_left(int r) {
		return min_left(r, [](S x) { return g(x); });
	}
	template <class G>
	int min_left(int r, G g) {
		assert(0 <= r && r <= _n);
		assert(g(e()));
		if (r == 0) return 0;
		r += size;
		for (int i = log; i >= 1; i--) push((r - 1) >> i);
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!g(op(d[r], sm))) {
				while (r < size) {
					push(r);
					r = (2 * r + 1);
					if (g(op(d[r], sm))) {
						sm = op(d[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = op(d[r], sm);
		} while ((r & -r) != r);
		return 0;
	}

 private:
	int _n, size, log;
	std::vector<S> d;
	std::vector<F> lz;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
	void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if (k < size) lz[k] = composition(f, lz[k]);
	}
	void push(int k) {
		all_apply(2 * k, lz[k]);
		all_apply(2 * k + 1, lz[k]);
		lz[k] = id();
	}
};

}	 // namespace atcoder
using namespace atcoder;

using S = struct {
	int tot, sz;
};
S op(S a, S b) { 
	return {a.tot + b.tot, a.sz + b.sz};
}
S e() { return {0, 0}; }
using F = int;
S mapping (F f, S x) { return {x.tot + f * x.sz, x.sz}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> M >> N;
	int K; cin >> K;
	struct Kunai {
		int x, y, dir, id;
		bool operator<(const Kunai &other) const {
			return tie(x, y) < tie(other.x, other.y);
		}
	};
	vector<Kunai> kunais(K);
	for (int i = 0; i < K; ++i) {
		cin >> kunais[i].y >> kunais[i].x >> kunais[i].dir;
		kunais[i].x--;
		kunais[i].y--;
		kunais[i].id = i;
	}

	// vector<string> g(N, string(M, ' '));
	// for (auto [x, y, dir, id] : kunais) {
	// 	if (dir == 0) g[x][y] = '>';
	// 	if (dir == 1) g[x][y] = '^';
	// 	if (dir == 2) g[x][y] = '<';
	// 	if (dir == 3) g[x][y] = 'v';
	// }
	// for (int i = 0; i < N; ++i) {
	// 	debug(g[i]);
	// }

	// - | \ /
	vector<map<int, set<Kunai>>> x_kunai(4), y_kunai(4), diag_kunai(4), anti_kunai(4);
	for (auto kunai : kunais) {
		auto [x, y, dir, id] = kunai;
		x_kunai[dir][x].insert(kunai);
		y_kunai[dir][y].insert(kunai);
		diag_kunai[dir][x-y].insert(kunai);
		anti_kunai[dir][x+y].insert(kunai);
	}

	struct Dist {
		int dist, stop_at_edge;
		bool operator<(const Dist &other) {
			return tie(dist, stop_at_edge) < tie(other.dist, other.stop_at_edge);
		}
		bool operator==(const Dist &other) {
			return tie(dist, stop_at_edge) == tie(other.dist, other.stop_at_edge);
		}
	};

	// assumption: a and b can possibly collide
	auto get_dist = [&](Kunai a, Kunai b) -> Dist {
		if (a.x == b.x) {
			int d = abs(b.y - a.y);
			return {d/2, d%2};
		}
		if (a.y == b.y) {
			int d = abs(b.x - a.x);
			return {d/2, d%2};
		}
		return {abs(b.x - a.x), 0};
	};

	map<int, Dist> dists;
	set<Kunai> to_process;
	set<Kunai> processing;
	auto solve = [&](auto self, Kunai kunai) -> Dist {
		auto [x, y, dir, id] = kunai;
		struct Stream {
			set<Kunai> &kunais;
			int inc;
			Kunai base;
			bool empty() {
				// if (kunais.empty()) return 1;
				if (inc == 1) return kunais.upper_bound(base) == kunais.end();
				else return kunais.lower_bound(base) == kunais.begin();
			}
			Kunai get() {
				if (inc == 1) return *kunais.upper_bound(base);
				return *(--kunais.lower_bound(base));
			}
			void pop() {
				if (inc == 1) kunais.erase(kunais.upper_bound(base));
				else kunais.erase(--kunais.lower_bound(base));
			}
		};
		auto calc = [&](vector<Stream> streams) -> Dist {
			while (true) {
				debug("into", x, y, dir, id);
				Dist best_possible = {(int)2e9, 1};
				vector<int> bests;
				for (int i = 0; i < streams.size(); ++i) {
					auto s = streams[i];
					debug(s.kunais.size());
					debug(s.empty());
					if (!s.empty()) {
						auto cand = s.get();
						auto dist = get_dist(kunai, cand);
						if (dist < best_possible) {
							bests.clear();
							best_possible = dist;
						}
						if (dist == best_possible) bests.push_back(i);
					}
				}
				debug(best_possible.dist, best_possible.stop_at_edge, bests);
				if (bests.empty())
					return {(int)2e9, 0};

				bool found = 0;
				for (int i : bests) {
					auto s = streams[i];
					if (s.empty()) continue;
					auto cand = s.get();
					auto dist = get_dist(kunai, cand);
					if (!(dist == best_possible)) continue;
					if (to_process.count(cand)) {
						auto nxt_dist = self(self, cand);
						if (nxt_dist == best_possible) found = 1;
					}
					else if (processing.count(cand)) found = 1;
					else {
						assert(dists[cand.id] < dist || dists[cand.id] == dist);
						if (dists[cand.id] == dist) found = 1;
					}
				}
				for (int i : bests) {
					auto s = streams[i];
					if (!s.empty()) {
						auto cand = s.get();
						auto dist = get_dist(kunai, cand);
						if (dist == best_possible) s.pop();
					}
				}
				if (found) return best_possible;
			}
		};

		to_process.erase(kunai);
		processing.insert(kunai);
		debug(x, y, dir, id);
		if (dir == 0) { 
			dists[id] = calc({Stream{anti_kunai[3][x+y], 0, kunai}, Stream{x_kunai[2][x], 1, kunai}, Stream{diag_kunai[1][x-y], 1, kunai}});
		}
		if (dir == 1) {
			dists[id] = calc({Stream{diag_kunai[0][x-y], 0, kunai}, Stream{y_kunai[3][y], 0, kunai}, Stream{anti_kunai[2][x+y], 0, kunai}});
		}
		if (dir == 2) {
			dists[id] = calc({Stream{anti_kunai[1][x+y], 1, kunai}, Stream{x_kunai[0][x], 0, kunai}, Stream{diag_kunai[3][x-y], 0, kunai}});
		}
		if (dir == 3) {
			dists[id] = calc({Stream{diag_kunai[2][x-y], 1, kunai}, Stream{y_kunai[1][y], 1, kunai}, Stream{anti_kunai[0][x+y], 1, kunai}});
		}
		processing.erase(kunai);
		return dists[id];
	};

	for (auto k : kunais) {
		to_process.insert(k);
	}
	while (!to_process.empty()) {
		Kunai k = *to_process.begin();
		solve(solve, k);
	}
	auto in = [&](int i, int j) {
		return i >= 0 && j >= 0 && i < N && j < M;
	};

	for (auto &[idx, dist] : dists) {
		auto [x, y, dir, _] = kunais[idx];
		if (dir == 0) dist.dist = min(dist.dist, M-y-1);
		if (dir == 1) dist.dist = min(dist.dist, x);
		if (dir == 2) dist.dist = min(dist.dist, y);
		if (dir == 3) dist.dist = min(dist.dist, N-x-1);
	}

	struct Rect { int x1, x2, y1, y2; };
	vector<Rect> rects(K);
	for (auto [idx, dist] : dists) {
		auto [x, y, dir, _] = kunais[idx];
		if (dir == 0) rects[idx] = {x, x, y, y + dist.dist};
		if (dir == 2) rects[idx] = {x, x, y - dist.dist, y};
		if (dir == 1) rects[idx] = {x - dist.dist, x, y, y};
		if (dir == 3) rects[idx] = {x, x + dist.dist, y, y};
	}

	ll ans = 0;
	map<int, vector<Rect>> verts, horis;
	for (auto r : rects) {
		auto [x1, x2, y1, y2] = r;
		if (y1 == y2) verts[y1].push_back(r);
		if (x1 == x2) horis[x1].push_back(r);
	}
	struct Event {
		// typ 0 is insert vertical segment
		// 		 1 is subtract, 2 is add
		int typ, l, r;
	};
	map<int, vector<Event>> events;
	debug("VERTICALS");
	for (auto [y, strips] : verts) {
		sort(strips.begin(), strips.end(), [&](Rect a, Rect b) { return a.x1 < b.x1; });
		int lst_x = -1e9;
		int cur = -1e9-1;
		for (auto [x1, x2, y1, y2] : strips) {
			if (x1 > cur) {
				if (lst_x != -1e9) {
					events[y].push_back({0, lst_x, cur});
					debug(y, lst_x, cur);
				}
				ans += cur - lst_x + 1;
				lst_x = x1;
			}
			cur = max(cur, x2);
		}
		ans += cur - lst_x + 1;
		if (lst_x != -1e9) {
			events[y].push_back({0, lst_x, cur});
			debug(y, lst_x, cur);
		}
	}
	debug("HORIZONTALS");
	for (auto [x, strips] : horis) {
		sort(strips.begin(), strips.end(), [&](Rect a, Rect b) { return a.y1 < b.y1; });
		int lst_y = -1e9;
		int cur = -1e9-1;
		for (auto [x1, x2, y1, y2] : strips) {
			if (y1 > cur) {
				if (lst_y != -1e9) {
					events[lst_y-1].push_back({1, x});
					events[cur].push_back({2, x});
					debug(x, lst_y, cur);
				}
				ans += cur - lst_y + 1;
				lst_y = y1;
			}
			cur = max(cur, y2);
		}
		if (lst_y != -1e9) {
			events[lst_y-1].push_back({1, x});
			events[cur].push_back({2, x});
			debug(x, lst_y, cur);
		}
		ans += cur - lst_y + 1;
	}

	ll overlap = 0;
	vector<int> comp;
	for (auto [y, eves] : events) {
		for (auto [typ, l, r] : eves) {
			comp.push_back(l);
			if (typ == 0) comp.push_back(r);
		}
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	lazy_segtree<S, op, e, F, mapping, composition, id> st(vector<S>(comp.size(), {0, 1}));
	for (auto [y, eves] : events) {
		for (auto &[typ, l, r] : eves) {
			l = lower_bound(comp.begin(), comp.end(), l) - comp.begin();
			if (typ == 0) r = lower_bound(comp.begin(), comp.end(), r) - comp.begin();
		}
		sort(eves.begin(), eves.end(), [&](Event a, Event b) { return a.typ < b.typ; });
		for (auto [typ, l, r] : eves) {
			debug(y, typ, l, r);
			if (typ == 0) {
				st.apply(l, r+1, 1);
			}
			if (typ == 1) {
				overlap -= st.get(l).tot;
			}
			if (typ == 2) {
				overlap += st.get(l).tot;
			}
		}
	}

	debug(ans, overlap);
	ans -= overlap;
	cout << ans << '\n';

	// set<pair<int, int>> overlap;
	// for (auto [x1, x2, y1, y2] : rects) {
	// 	if (x1 != x2) continue;
	// 	for (auto [x1p, x2p, y1p, y2p] : rects) {
	// 		if (y1p != y2p) continue;
	// 		if (x1 >= x1p && x1 <= x2p && y1p >= y1 && y1p <= y2) {
	// 			overlap.insert({x1, y1p});
	// 		}
	// 	}
	// }

	// ans -= overlap.size();

	// naive rectangle union
	// vector<vector<int>> vis(N, vector<int>(M));
	// for (auto [idx, dist] : dists) {
	// 	auto [x, y, dir, _] = kunais[idx];
	// 	for (int d = 0; d <= dist.dist; ++d) {
	// 		vis[x][y] = 1;
	// 		x += dx[dir], y += dy[dir];
	// 	}
	// }
	// int ans = 0;
	// for (int i = 0; i < N; ++i) {
	// 	debug(vis[i]);
	// 	for (int j = 0; j < M; ++j) {
	// 		ans += vis[i][j];
	// 	}
	// }
	// cout << ans << '\n';
}
