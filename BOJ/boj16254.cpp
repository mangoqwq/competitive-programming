#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
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
using S = struct {
	ll sum, cnt; int mn;
};
S op(S a, S b) { return {a.sum + b.sum, a.cnt + b.cnt, min(a.mn, b.mn)}; }
S e() { return {0, 0, (int)1e9}; };

struct T {
	ll val, cnt;
	bool operator<(const T &other) const {
		return tie(val, cnt) < tie(other.val, other.cnt);
	}
};
T opt(T a, T b) { return min(a, b); }
T et() { return {(ll)1e18, 0}; }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, K; cin >> N >> K;
	vector<ll> a(N), psa(N+1);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		psa[i+1] = psa[i] + a[i];
	}

	vector<ll> comp = psa;
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	vector<int> idx(N+1);
	for (int i = 0; i <= N; ++i) {
		idx[i] = lower_bound(comp.begin(), comp.end(), psa[i]) - comp.begin();
	}

	auto h = [&](ll lambda) -> pair<ll, ll> {
		segtree<S, op, e> st(comp.size());
		ll base_sum = 0, base_cnt = 0;
		vector<int> back(N+1);
		st.set(idx[0], {0, 1, 0});
		for (int i = 1; i <= N; ++i) {
			int l = lower_bound(comp.begin(), comp.end(), psa[i] - lambda) - comp.begin();
			auto [sum, cnt, lst] = st.prod(0, l);
			back[i] = lst;
			base_sum += (psa[i] - lambda) * cnt - sum;
			base_cnt += cnt;

			auto [old_sum, old_cnt, old_lst] = st.get(idx[i]);
			st.set(idx[i], {old_sum + psa[i], old_cnt + 1, min(old_lst, i)});
		}

		vector<int> covered(N+1);
		int reach = 1e9;
		for (int i = N; i >= 1; --i) {
			reach = min(reach, back[i]+1);
			if (reach <= i) covered[i] = 1;
		}

		vector<ll> dp(N+1, -1e18), dp_cnt(N+1);
		segtree<T, opt, et> st2(N+1);
		st2.set(0, {0, 0});
		dp[0] = 0;
		ll mnpsa = 0;
		int lst_uncovered = 0;
		for (int i = 1; i <= N; ++i) {
			if (!covered[i]) lst_uncovered = i;
			if (lst_uncovered) {
				T t = st2.prod(0, lst_uncovered);
				dp[i] = psa[i] - t.val - lambda;
				dp_cnt[i] = t.cnt + 1;
			}
			if (covered[i]) {
				if (dp[i-1] > dp[i] || (dp[i-1] == dp[i] && dp_cnt[i-1] < dp_cnt[i])) {
					dp[i] = dp[i-1];
					dp_cnt[i] = dp_cnt[i-1];
				}
			}
			mnpsa = min(mnpsa, psa[i]);
			st2.set(i, {mnpsa - dp[i], dp_cnt[i]});
		}
		ll cnt = base_cnt + dp_cnt[N];
		ll sum = base_sum + dp[N];
		return {cnt, -sum - lambda * K};
	};

	ll lo = -5e11, hi = 5e11;
	while (lo < hi) {
		ll mi = (lo + hi) >> 1;
		auto [x, hx] = h(mi);
		if (x <= K) hi = mi;
		else lo = mi + 1;
	}
	auto [x, hx] = h(lo);
	cout << -hx << '\n';
}
