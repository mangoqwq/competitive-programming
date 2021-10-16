#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 15;

int N, K, h[MN], l[MN], r[MN]; ll dp[MN];
vector<int> eve[MN];

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

ll op(ll a, ll b){ return min(a, b); }
ll e(){ return inf; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    atcoder::segtree<ll, op, e> st(N + 5);
    for (int i = 1; i <= N; ++i) cin >> h[i];
    
    int same = 1;
    l[1] = 1;
    for (int i = 2; i <= N; ++i){
        if (h[i] < h[i - 1]) l[i] = i, same = i;
        if (h[i] > h[i - 1]) l[i] = l[i - 1], same = i;
        if (h[i] == h[i - 1]){
            if (i - K < same) l[i] = l[i - 1];
            else l[i] = i - K;
        }
    }
    same = N;
    r[N] = N;
    for (int i = N - 1; i >= 1; --i){
        if (h[i] < h[i + 1]) r[i] = i, same = i;
        if (h[i] > h[i + 1]) r[i] = r[i + 1], same = i;
        if (h[i] == h[i + 1]){
            if (i + K > same) r[i] = r[i + 1];
            else r[i] = i + K;
        }
    }
    for (int i = 1; i <= N; ++i) eve[r[i]].push_back(l[i]), dp[i] = inf;

    dp[0] = 0, st.set(0, 0);
    for (int i = 1; i <= N; ++i){
        for (int l : eve[i]){
            // for (int j = l - 1; j < i; ++j){
            //     dp[i] = min(dp[i], dp[j] + 1);
            // }

            dp[i] = min(dp[i], st.prod(l - 1, i) + 1);
            // dp[i] = min(dp[i], dp[l - 1]);
        }
        st.set(i, dp[i]);
    }
    cout << dp[N] << '\n';
}
