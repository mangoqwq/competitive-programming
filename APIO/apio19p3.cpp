#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 10;

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
namespace{
    using S = bool;
    S op(S a, S b){ return (a & b ? 1 : 0); }
    S e(){ return 1; }
    bool f(bool x){ return x; }
}
atcoder::segtree<S, op, e> st(MN + 10);
struct Fenwick{
    int a[MN], T = 0, hist[MN * 2], in[MN];
    void upd(int i, int val){ if (!in[i]) hist[++T] = i, in[i] = 1; for (++i; i < MN; i += i & -i) a[i] += val; }
    void remove(int i){ in[i] = 0; for (++i; i < MN; i += i & -i) a[i] = 0; }
    int qry(int i){ int ret = 0; for (++i; i; i -= i & -i) ret += a[i]; return ret; }
    int qry(int l, int r){ return qry(r) - qry(l - 1); }
    void reset(){
        for (int i = 1; i <= T; ++i) remove(hist[i]);
        T = 0;
    }
} bit;
int N, Q, ans[MN]; bool arr[MN];
struct Query{ int op, t, l, r; } queries[3 * MN], points[3 * MN];
int qT, pT;

void cdq2(vector<int> &qs, int L, int R){
    if (qs.empty() || L > R) return;

    bool bad = 1;
    for (int idxs : qs) if (points[idxs].op == 2){ bad = 0; break; }
    if (bad) return;

    int mid = (L + R) >> 1;
    ll tot = 0;
    vector<int> ql, qr;

    for (int idxs : qs){
        auto &[op, t, l, r] = points[idxs];

        if (op == 1){
            if (l <= mid) bit.upd(r, t), tot += t;
        }
        if (op == 2){
            if (l >= mid) ans[t] += (tot - bit.qry(r - 1));
        }

        if (l < mid) ql.push_back(idxs);
        if (l > mid) qr.push_back(idxs);
    }

    bit.reset();
    cdq2(ql, L, mid - 1), cdq2(qr, mid + 1, R);
}

void cdq1(vector<int> &qs, int L, int R){
    if (qs.empty() || L > R) return;

    bool bad = 1;
    for (int idxs : qs) if (queries[idxs].op == 2){ bad = 0; break; }
    if (bad) return;

    int mid = (L + R) >> 1;
    vector<int> ql, qr;
    int last = 0;
    pT = 0;

    for (int idxs : qs){
        auto &[op, t, l, r] = queries[idxs];
        
        int lower = st.min_left<f>(mid + 1);
        int upper = st.max_right<f>(mid) - 1;
        lower = max(lower, L), upper = min(upper, R);
        points[pT++] = {1, t - last, lower, upper};
        last = t;
        
        if (op == 1){
            arr[l] ^= 1;
            st.set(l, arr[l]);
            
            if (l < mid) ql.push_back(idxs);
            if (l > mid) qr.push_back(idxs);
        }
        if (op == 2){
            if (l > mid) qr.push_back(idxs);
            else if (r < mid) ql.push_back(idxs);
            else points[pT++] = {2, t, l, r};
        }
    }

    vector<int> qs2(pT);
    iota(qs2.begin(), qs2.end(), 0);
    cdq2(qs2, 1, N);

    for (int i = L - 1; i <= R + 1; ++i){
        if (arr[i]) st.set(i, 0), arr[i] = 0;
    }
    cdq1(ql, L, mid - 1), cdq1(qr, mid + 1, R);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        st.set(i, 0);
        if (c == '1') queries[qT++] = {1, 0, i};   
    }
    st.set(0, 0), st.set(N + 1, 0);
    for (int i = 1; i <= Q; ++i){
        string s; cin >> s;
        if (s == "toggle"){
            int l; cin >> l;
            queries[qT++] = {1, i, l};
        }
        if (s == "query"){
            int l, r; cin >> l >> r; r--;
            queries[qT++] = {2, i, l, r};
        }
    }
    vector<int> qs(qT);
    iota(qs.begin(), qs.end(), 0);
    cdq1(qs, 1, N);
    for (auto &[op, t, l, r] : queries){
        if (op == 2){
            cout << ans[t] << '\n';
        }
    }
}
