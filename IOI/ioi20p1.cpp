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

// Source: atcoder library
// Documentation:
// https://atcoder.github.io/ac-library/production/document_en/segtree.html
// https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
 public:
	segtree() : segtree(0) {}
	explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
	explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
		log = internal::ceil_pow2(_n);
		size = 1 << log;
		d = std::vector<S>(2 * size, e());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) const {
		assert(0 <= p && p < _n);
		return d[p + size];
	}

	S prod(int l, int r) const {
		assert(0 <= l && l <= r && r <= _n);
		S sml = e(), smr = e();
		l += size;
		r += size;

		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}

	S all_prod() const { return d[1]; }

	template <bool (*f)(S)>
	int max_right(int l) const {
		return max_right(l, [](S x) { return f(x); });
	}
	template <class F>
	int max_right(int l, F f) const {
		assert(0 <= l && l <= _n);
		assert(f(e()));
		if (l == _n) return _n;
		l += size;
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!f(op(sm, d[l]))) {
				while (l < size) {
					l = (2 * l);
					if (f(op(sm, d[l]))) {
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

	template <bool (*f)(S)>
	int min_left(int r) const {
		return min_left(r, [](S x) { return f(x); });
	}
	template <class F>
	int min_left(int r, F f) const {
		assert(0 <= r && r <= _n);
		assert(f(e()));
		if (r == 0) return 0;
		r += size;
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!f(op(d[r], sm))) {
				while (r < size) {
					r = (2 * r + 1);
					if (f(op(d[r], sm))) {
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

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}	 // namespace atcoder
using namespace atcoder;
using pii = pair<int, int>;

struct S {
	pii mn; int arg_mn;
};
S op(S a, S b) { return (a.mn <= b.mn ? a : b); }
S e() { return {{(int)1e9, (int)1e9}, -1}; }
using F = pii;
S mapping(F f, S x) { return {{x.mn.first + f.first, x.mn.second + f.second}, x.arg_mn}; }
F composition(F f, F g) {
	return {f.first + g.first, f.second + g.second};
}
F id() { return {0, 0}; }
struct S2 {
	int mx, arg_mx;
};
S2 op2(S2 a, S2 b) { return (a.mx >= b.mx ? a : b); }
S2 e2() { return {-1, -1}; }

const int L = 18;
int N, K;
vector<int> R;
vector<int> valid;
vector<vector<ll>> stl, str;

int dist(int i, int j) { // i -> j
	if (j >= i) return j - i;
	return j + N - i;
};

void init(int _K, vector<int> _R) {
	K = _K;
	R = _R;
	N = R.size();
	if (N == K) return;
	debug(R);
	lazy_segtree<S, op, e, F, mapping, composition, id> st(N);


	auto apply = [&](int l, int r, F f) -> void {
		if (l <= r) st.apply(l, r, f);
		else {
			st.apply(l, N, f); st.apply(0, r, f);
		}
	};
	auto qry = [&](int l, int r) -> S {
		if (l <= r) return st.prod(l, r);
		return op(st.prod(l, N), st.prod(0, r));
	};

	auto fix_range = [&](auto self, int l, int r) -> void {
		// debug(l, r);
		auto [mn, arg_mn] = qry(l, r);
		if (mn.first > 0) return;
		apply((arg_mn + 1), (arg_mn + K) % N, {0, 1});
		self(self, (arg_mn + 1), r);
		self(self, l, arg_mn);
	};

	for (int i = 0; i < N; ++i) {
		st.set(i, {{R[i], 0}, i});
	}
	fix_range(fix_range, 0, N);

	auto printst = [&]() -> void {
		vector<pii> vec(N);
		for (int i = 0; i < N; ++i) {
			vec[i] = st.get(i).mn;
		}
		debug(vec);
	};

	// printst();
	valid = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		auto [mn, arg_mn] = qry(0, N);
		debug(mn, arg_mn);
		assert(mn == (pii{0,0}));
		valid[arg_mn] = N-1 - i;
		apply(arg_mn, arg_mn+1, {(int)1e9, (int)1e9});

		apply((arg_mn + 1) % N, (arg_mn + K) % N, F{0, -1});
		apply((arg_mn - K + 1 + N) % N, arg_mn, F{-1, 0});
		fix_range(fix_range, (arg_mn - K + 1 + N) % N, arg_mn);
		// printst();
	}

	vector<int> ord(N);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j) { return valid[i] < valid[j]; });

	segtree<S2, op2, e2> st2(N);

	auto qry2 = [&](int l, int r) -> S2 {
		if (l <= r) return st2.prod(l, r);
		return op2(st2.prod(l, N), st2.prod(0, r));
	};
	vector<int> nxt(N), lst(N);
	for (int i : ord) {
		nxt[i] = qry2(i, (i+K)%N).arg_mx;
		lst[i] = qry2((i-K+1 + N)%N, i+1).arg_mx;
		st2.set(i, {valid[i], i});
	}

	stl = vector<vector<ll>>(N, vector<ll>(L));
	str = vector<vector<ll>>(N, vector<ll>(L));
	for (int i = 0; i < N; ++i) {
		if (lst[i] == -1) stl[i][0] = 0;
		else stl[i][0] = dist(lst[i], i);
		if (nxt[i] == -1) str[i][0] = 0;
		else str[i][0] = dist(i, nxt[i]);
	}
	for (int l = 1; l < L; ++l) {
		for (int i = 0; i < N; ++i) {
			stl[i][l] = stl[i][l-1] + stl[((i - stl[i][l-1]) % N + N) % N][l-1];
			str[i][l] = str[i][l-1] + str[(i + str[i][l-1]) % N][l-1];
		}
	}
	debug(valid);
	debug(lst);
	debug(nxt);
}

int compare_plants(int i, int j) {
	if (N == K) {
		if (R[i] > R[j]) return -1;
		else return 1;
	}

	if (valid[i] < valid[j]) return -compare_plants(j, i);
	bool reachable = 0;
	// left
	{
		int idx = i;
		ll need = dist(j, idx);
		for (int l = L-1; l >= 0; --l) {
			// debug(idx, stl[idx][l], need);
			if (stl[idx][l] < need) {
				need -= stl[idx][l];
				idx = ((idx - stl[idx][l]) % N + N) % N;
			}
		}
		need -= stl[idx][0];
		idx = ((idx - stl[idx][0]) % N + N) % N;
		if (need <= 0) {
			reachable |= valid[idx] >= valid[j];
		}
	}
	// debug(reachable);
	// right
	{
		int idx = i;
		ll need = dist(idx, j);
		// debug(idx, need);
		for (int l = L-1; l >= 0; --l) {
			// debug(idx, str[idx][l], need);
			if (str[idx][l] < need) {
				need -= str[idx][l];
				idx = (idx + str[idx][l]) % N;
			}
		}
		// debug(idx, str[idx][0], need);
		need -= str[idx][0];
		idx = (idx + str[idx][0]) % N;
		if (need <= 0) {
			reachable |= valid[idx] >= valid[j];
		}
	}
	return reachable ? 1 : 0;
}

#ifdef _DEBUG
int main() {
	cin.tie(0)->sync_with_stdio(0);
	auto make = [&](int k, vector<int> v) {
		int n = v.size();
		vector<int> ret(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < k; ++j) {
				int x = (i+j) % n;
				if (v[i] < v[x]) ret[i]++;
			}
		}
		return ret;
	};
	mt19937 mt(0);
	auto rand = [&](int n, int k) -> vector<int> {
		vector<int> a(n);
		iota(a.begin(), a.end(), 0);
		shuffle(a.begin(), a.end(), mt);
		return make(k, a);
	};
	auto test1 = [&]() -> void {
		init(3, {0, 1, 1, 2});
		cout << compare_plants(0, 2) << '\n';
		cout << compare_plants(1, 2) << '\n';
	};
	auto test2 = [&]() -> void {
		init(K, {0, 3, 3, 2, 0, 2, 0});
	};
	auto test3 = [&]() -> void {
		init(5, {3, 4, 2, 0, 1});
		cout << compare_plants(0, 4) << '\n';
	};
	auto test4 = [&]() -> void {
		init(3, {0, 2, 2, 1, 0, 2, 1, 0});
	};
	auto test5 = [&]() -> void {
		int K = 100;
		int N = 190;
		init(K, rand(N, K));
		// debug(compare_plants(0, 13));
		for (int i = 0; i < N; ++i) {
			for (int j = i+1; j < N; ++j) {
				auto want = valid[i] > valid[j] ? 1 : -1;
				auto ans = compare_plants(i, j);
				debug(i, j, ans, want);
				assert(ans == want);
			}
		}
	};
	auto test6 = [&]() -> void { 
		init(2, {0, 1, 0, 1});
		cout << compare_plants(0, 3) << '\n';
		cout << compare_plants(1, 3) << '\n';
	};
	test5();
	// init(2, {0, 1, 0, 1});
}
#endif
