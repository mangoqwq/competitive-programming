#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
	int n = int(s.size());
	std::vector<int> sa(n);
	std::iota(sa.begin(), sa.end(), 0);
	std::sort(sa.begin(), sa.end(), [&](int l, int r) {
		if (l == r) return false;
		while (l < n && r < n) {
			if (s[l] != s[r]) return s[l] < s[r];
			l++;
			r++;
		}
		return l == n;
	});
	return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
	int n = int(s.size());
	std::vector<int> sa(n), rnk = s, tmp(n);
	std::iota(sa.begin(), sa.end(), 0);
	for (int k = 1; k < n; k *= 2) {
		auto cmp = [&](int x, int y) {
			if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
			int rx = x + k < n ? rnk[x + k] : -1;
			int ry = y + k < n ? rnk[y + k] : -1;
			return rx < ry;
		};
		std::sort(sa.begin(), sa.end(), cmp);
		tmp[sa[0]] = 0;
		for (int i = 1; i < n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}
		std::swap(tmp, rnk);
	}
	return sa;
}

// SA-IS, linear-time suffix array construction
// Reference:
// G. Nong, S. Zhang, and W. H. Chan,
// Two Efficient Algorithms for Linear Time Suffix Array Construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
	int n = int(s.size());
	if (n == 0) return {};
	if (n == 1) return {0};
	if (n == 2) {
		if (s[0] < s[1]) {
			return {0, 1};
		} else {
			return {1, 0};
		}
	}
	if (n < THRESHOLD_NAIVE) {
		return sa_naive(s);
	}
	if (n < THRESHOLD_DOUBLING) {
		return sa_doubling(s);
	}

	std::vector<int> sa(n);
	std::vector<bool> ls(n);
	for (int i = n - 2; i >= 0; i--) {
		ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
	}
	std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
	for (int i = 0; i < n; i++) {
		if (!ls[i]) {
			sum_s[s[i]]++;
		} else {
			sum_l[s[i] + 1]++;
		}
	}
	for (int i = 0; i <= upper; i++) {
		sum_s[i] += sum_l[i];
		if (i < upper) sum_l[i + 1] += sum_s[i];
	}

	auto induce = [&](const std::vector<int>& lms) {
		std::fill(sa.begin(), sa.end(), -1);
		std::vector<int> buf(upper + 1);
		std::copy(sum_s.begin(), sum_s.end(), buf.begin());
		for (auto d : lms) {
			if (d == n) continue;
			sa[buf[s[d]]++] = d;
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		sa[buf[s[n - 1]]++] = n - 1;
		for (int i = 0; i < n; i++) {
			int v = sa[i];
			if (v >= 1 && !ls[v - 1]) {
				sa[buf[s[v - 1]]++] = v - 1;
			}
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		for (int i = n - 1; i >= 0; i--) {
			int v = sa[i];
			if (v >= 1 && ls[v - 1]) {
				sa[--buf[s[v - 1] + 1]] = v - 1;
			}
		}
	};

	std::vector<int> lms_map(n + 1, -1);
	int m = 0;
	for (int i = 1; i < n; i++) {
		if (!ls[i - 1] && ls[i]) {
			lms_map[i] = m++;
		}
	}
	std::vector<int> lms;
	lms.reserve(m);
	for (int i = 1; i < n; i++) {
		if (!ls[i - 1] && ls[i]) {
			lms.push_back(i);
		}
	}

	induce(lms);

	if (m) {
		std::vector<int> sorted_lms;
		sorted_lms.reserve(m);
		for (int v : sa) {
			if (lms_map[v] != -1) sorted_lms.push_back(v);
		}
		std::vector<int> rec_s(m);
		int rec_upper = 0;
		rec_s[lms_map[sorted_lms[0]]] = 0;
		for (int i = 1; i < m; i++) {
			int l = sorted_lms[i - 1], r = sorted_lms[i];
			int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
			int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
			bool same = true;
			if (end_l - l != end_r - r) {
				same = false;
			} else {
				while (l < end_l) {
					if (s[l] != s[r]) {
						break;
					}
					l++;
					r++;
				}
				if (l == n || s[l] != s[r]) same = false;
			}
			if (!same) rec_upper++;
			rec_s[lms_map[sorted_lms[i]]] = rec_upper;
		}

		auto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

		for (int i = 0; i < m; i++) {
			sorted_lms[i] = lms[rec_sa[i]];
		}
		induce(sorted_lms);
	}
	return sa;
}

}	 // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
	assert(0 <= upper);
	for (int d : s) {
		assert(0 <= d && d <= upper);
	}
	auto sa = internal::sa_is(s, upper);
	return sa;
}

template <class T>
std::vector<int> suffix_array(const std::vector<T>& s) {
	int n = int(s.size());
	std::vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
	std::vector<int> s2(n);
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (i && s[idx[i - 1]] != s[idx[i]]) now++;
		s2[idx[i]] = now;
	}
	return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return internal::sa_is(s2, 255);
}

// Reference:
// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
// Applications
template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
													 const std::vector<int>& sa) {
	int n = int(s.size());
	assert(n >= 1);
	std::vector<int> rnk(n);
	for (int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}
	std::vector<int> lcp(n - 1);
	int h = 0;
	for (int i = 0; i < n; i++) {
		if (h > 0) h--;
		if (rnk[i] == 0) continue;
		int j = sa[rnk[i] - 1];
		for (; j + h < n && i + h < n; h++) {
			if (s[j + h] != s[i + h]) break;
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return lcp_array(s2, sa);
}

// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T>
std::vector<int> z_algorithm(const std::vector<T>& s) {
	int n = int(s.size());
	if (n == 0) return {};
	std::vector<int> z(n);
	z[0] = 0;
	for (int i = 1, j = 0; i < n; i++) {
		int& k = z[i];
		k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
		while (i + k < n && s[k] == s[i + k]) k++;
		if (j + z[j] < i + z[i]) j = i;
	}
	z[0] = n;
	return z;
}

std::vector<int> z_algorithm(const std::string& s) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return z_algorithm(s2);
}

}	 // namespace atcoder

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

using S = int;
S op(S a, S b) { return min(a, b); }
S e() { return 2e9; }
using F = int;
S mapping(F f, S x) { return x - f; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
bool f(S x) { return x != 0; }

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
	T qry(int l, int r) { return qry(r - 1) - qry(l - 1); }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	int N = s.size();
	ll K; cin >> K;
	auto sa = suffix_array(s);
	auto lcp = lcp_array(s, sa);
	lcp.push_back(0);
	debug(sa);
	debug(lcp);
	lazy_segtree<S, op, e, F, mapping, composition, id> st(lcp);
	Fenwick<int> bit(N);
	auto use = [&](int l, int r, int val) {
		bit.ins(l, val);
		bit.ins(r, -val);
	};
	auto uses = [&](int i) {
		return bit.qry(0, i+1);
	};
	int l = 0;
	while (true) {
		int i = st.max_right<f>(l);
		if (i == l) {
			int left = (N - sa[i]) - uses(i);
			if (left >= K) {
				cout << s.substr(sa[i], uses(i) + K) << '\n';
				return 0;
			}
			K -= left;
			l++;
		}
		else {
			ll mn = st.prod(l, i);
			i++;
			if (mn * (i-l) >= K) {
				K--;
				debug(K, i-l);
				debug(uses(l));
				int len = uses(l) + K/(i-l) + 1;
				debug(len);
				cout << s.substr(sa[l], len) << '\n';
				return 0;
			}
			K -= mn * (i-l);
			st.apply(l, i-1, mn);
			use(l, i, mn);
		}
		debug(K, l);
		// for (int i = 0; i < N; ++i) {
		// 	cout << st.get(i) << " ";
		// }
		// cout << '\n';
		// cout.flush();
	}
}
