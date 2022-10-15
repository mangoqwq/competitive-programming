#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MN = 5e5 + 10, MT = 5e5 + 10;

int N;

// Source: Atcoder Library
// https://github.com/atcoder/ac-library

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

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
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

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
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
public:
    void ins(int l, int r, F val){ apply(l - 2, r - 1, val); }
};

struct S{ int mn, cnt; };
S op(S l, S r){
    if (l.mn == r.mn) return {l.mn, l.cnt + r.cnt};
    return l.mn < r.mn ? l : r;
}
S e(){ return {0, 0}; };
S mapping(int l, S r){ return {r.mn + l, r.cnt}; }
int composition(int l, int r){ return l + r; }
int id(){ return 0; }

lazy_segtree<S, op, e, int, mapping, composition, id> st;

int ord[MN], lc1[MN], rc1[MN], lc2[MN], rc2[MN], par[MN];
vector<int> adj[MN];
vector<int> ins[MT], rem[MT];

void dfs(int v){
    for (int to : adj[v]){
        if (to == par[v]) continue;
        dfs(to);
        lc1[v] = min(lc1[v], ord[to]);
        rc1[v] = max(rc1[v], ord[to]);
        lc2[v] = min(lc2[v], lc1[to]);
        rc2[v] = max(rc2[v], rc1[to]);
    }
}

void upd(int v, int val){
    if (lc2[v] != inf){
        st.ins(lc2[v], rc2[v], val);
    }
    int p = par[v];
    if (p){
        if (p != 1){
            st.ins(ord[p], ord[p], val);
        }
        st.ins(ord[v], ord[v], -val);
        st.ins(lc1[p], rc1[p], val);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    st = lazy_segtree<S, op, e, int, mapping, composition, id>(vector<S>(N - 1, {0, 1}));
    for (int i = 1; i <= N - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int T = 0;
    queue<int> q;
    q.push(1);
    ord[1] = ++T;
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int to : adj[v]){
            if (ord[to]) continue;
            ord[to] = ++T;
            par[to] = v;
            q.push(to);
        }
    }

    ms(lc1, 0x3f), ms(lc2, 0x3f);
    dfs(1);

    int Q; cin >> Q >> T;
    while (Q--){
        int v, a, b; cin >> v >> a >> b;
        ins[a].push_back(v);
        rem[b].push_back(v);
    }

    for (int i = 1; i <= T; ++i){
        for (int v : ins[i]) upd(v, 1);

        auto [mn, cnt] = st.all_prod();
        if (mn == 0) cout << N - cnt << '\n';
        else cout << N << '\n';

        for (int v : rem[i]) upd(v, -1);
    }
}
