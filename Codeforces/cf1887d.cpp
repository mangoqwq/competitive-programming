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
using S = struct {
	int mn, mx;
};
S op(S a, S b) { return {min(a.mn, b.mn), max(a.mx, b.mx)}; }
S e() { return {(int)1e9, 0}; }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N);
	vector<int> idx(N+1);
	atcoder::segtree<S, op, e> st(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		idx[a[i]] = i;
		st.set(i, {a[i], a[i]});
	}
	struct Query { int l, r, id; };
	int Q; cin >> Q;
	vector<Query> qs;
	for (int i = 0; i < Q; ++i) {
		int l, r; cin >> l >> r; l--;
		qs.push_back({l, r, i});
	}

	vector<int> mx(N), mn(N);
	vector<vector<Query>> queries(N);
	vector<int> ans(Q);
	auto go = [&](auto self, int l, int r, vector<Query> qs) -> void {
		if (qs.empty()) return;
		if (l+1 == r) {
			for (auto [l, r, id] : qs) ans[id] = 1;
			return;
		}

		for (int i = l; i < r; ++i) {
			queries[i].clear();
		}

		int m = (l+r) >> 1;
		vector<Query> lc, cur, rc;
		for (auto q : qs) {
			if (q.r <= m) lc.push_back(q);
			else if (q.l >= m) rc.push_back(q);
			else {
				queries[q.l].push_back(q);
				queries[q.r-1].push_back(q);
			}
		}

		int amx = 0, amn = 1e9;
		for (int i = m; i < r; ++i) {
			amx = max(amx, a[i]);
			amn = min(amn, a[i]);
			mx[i] = amx;
			mn[i] = amn;
		}
		amx = 0, amn = 1e9;
		for (int i = m-1; i >= l; --i) {
			amx = max(amx, a[i]);
			amn = min(amn, a[i]);
			mx[i] = amx;
			mn[i] = amn;
		}

		debug(l, r);

		int small = 0;
		map<int, int> mp;
		for (int i = m; i < r; ++i) {
			if (mx[i] == a[i]) {
				mp[a[i]] = a[i];
				small = a[i];
				// hi = a[i];
			}
			else {
				auto l = idx[mp.upper_bound(a[i])->first];
				mp[a[i]] = min(mp[st.prod(l, i).mn], a[i]);
			}
			debug(a[i], mp[a[i]]);
			for (auto [l, r, id] : queries[i]) {
				if (mn[r-1] > mx[l]) ans[id] = 1;
				if (mx[l] < mp[a[i]]) ans[id] = 1;
				debug(ans[id]);
			}
		}

		mp.clear();
		for (int i = m-1; i >= l; --i) {
			if (mn[i] == a[i]) {
				mp[a[i]] = a[i];
			}
			else {
				auto r = idx[(--mp.upper_bound(a[i]))->first];
				mp[a[i]] = max(mp[st.prod(i+1, r+1).mx], a[i]);
			}
			for (auto [l, r, id] : queries[i]) {
				debug(mp[a[i]]);
				if (mn[r-1] > mx[l]) ans[id] = 1;
				if (mn[r-1] > mp[a[i]]) ans[id] = 1;
				debug(ans[id]);
			}
		}
		// debug(l, r);

		self(self, l, m, lc);
		self(self, m, r, rc);
	};
	go(go, 0, N, qs);
	for (int i = 0; i < Q; ++i) {
		cout << (ans[i] ? "Yes" : "No") << '\n';
	}
}
