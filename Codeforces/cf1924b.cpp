#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// Source: atcoder library
// Documentation:
// https://atcoder.github.io/ac-library/production/document_en/segtree.html
// https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
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
using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, Q; cin >> N >> M >> Q;
	set<int> harbours;
	vector<int> loc(M);
	vector<int> val(N);
	for (int i = 0; i < M; ++i) {
		int x; cin >> x; x--;
		loc[i] = x;
		harbours.insert(x);
	}
	for (int i = 0; i < M; ++i) {
		cin >> val[loc[i]];
	}
	auto calc = [&](int i) -> ll {
		assert(harbours.count(i));
		auto it = harbours.find(i);
		int j = *(--it);
		ll d = i - j;
		return d * (d-1) / 2 * val[j];
	};

	segtree<S, op, e> st(N);
	for (int x : harbours) {
		if (x == 0) continue;
		debug(calc(x));
		st.set(x, calc(x));
	}

	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int x, v; cin >> x >> v; x--;
			val[x] = v;
			auto j = *harbours.upper_bound(x);
			harbours.insert(x);
			st.set(x, calc(x));
			st.set(j, calc(j));
		}
		if (op == 2) {
			int l, r; cin >> l >> r; l--; r--;
			auto ql = *harbours.lower_bound(l);
			auto qr = *(--harbours.upper_bound(r));
			debug(l, r, ql, qr);
			if (ql > qr) {
				auto nxt = *harbours.upper_bound(r);
				ll dp = nxt - l + 1;
				ll dm = nxt - r;
				ll ans = (dp * (dp-1) - dm * (dm-1)) / 2 * val[qr];				
				cout << ans << '\n';
				continue;
			}
			ll ans = st.prod(ql+1, qr+1);
			debug(ans);
			if (l != ql) {
				auto lst = *(--harbours.upper_bound(l));
				ll d = ql - l + 1;
				ans += d * (d-1) / 2 * val[lst];
			}
			if (r != qr) {
				auto nxt = *harbours.upper_bound(r);
				ll dp = nxt - qr;
				ll dm = nxt - r;
				ans += (dp * (dp-1) - dm * (dm-1)) / 2 * val[qr];
			}
			cout << ans << '\n';
		}
	}
}
