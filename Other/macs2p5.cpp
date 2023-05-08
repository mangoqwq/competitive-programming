#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// Source: atcoder library
// Documentation: https://atcoder.github.io/ac-library/production/document_en/segtree.html
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

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
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

		template <bool (*f)(S)> int max_right(int l) const {
				return max_right(l, [](S x) { return f(x); });
		}
		template <class F> int max_right(int l, F f) const {
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

		template <bool (*f)(S)> int min_left(int r) const {
				return min_left(r, [](S x) { return f(x); });
		}
		template <class F> int min_left(int r, F f) const {
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

}  // namespace atcoder

using S = ll;
S op(S a, S b){
	return a+b;
}
S e(){ return 0; }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> comp;
	struct Line {
		int x1, y1, x2, y2;
	};
	vector<Line> L;
	for (int i = 0; i < N; ++i){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		comp.push_back(x1);
		comp.push_back(y1);
		comp.push_back(x2);
		comp.push_back(y2);
		L.push_back({x1, y1, x2, y2});
	}
	sort(comp.begin(), comp.end());
	const int MN = 4e6;
	struct Eve {
		int t, l, r;
		bool operator<(const Eve &other) const{
			return t < other.t;
		}
	};
	vector<vector<Eve>> eve(MN + 10);
	for (int i = 0; i < N; ++i){
		L[i].x1 = lower_bound(comp.begin(), comp.end(), L[i].x1) - comp.begin();
		L[i].y1 = lower_bound(comp.begin(), comp.end(), L[i].y1) - comp.begin();
		L[i].x2 = lower_bound(comp.begin(), comp.end(), L[i].x2) - comp.begin();
		L[i].y2 = lower_bound(comp.begin(), comp.end(), L[i].y2) - comp.begin();
		if (L[i].x1 == L[i].x2){
			eve[L[i].x1].push_back({2, L[i].y1, L[i].y2});
		}
		else{
			eve[L[i].x1].push_back({0, L[i].y1, 0});
			eve[L[i].x2+1].push_back({1, L[i].y1, 0});
		}
	}
	ll ans = 0;
	atcoder::segtree<S, op, e> st(MN + 10);
	for (int i = 0; i <= MN; ++i){
		sort(eve[i].begin(), eve[i].end());
		for (auto [t, l, r] : eve[i]){
			if (t == 0){
				debug(0, l);
				st.set(l, st.get(l) + 1);
			}
			if (t == 1){
				debug(1, l);
				st.set(l, st.get(l) - 1);
			}
			if (t == 2){
				ans += st.prod(l, r+1);
			}
		}
	}
	cout << ans << '\n';
}
