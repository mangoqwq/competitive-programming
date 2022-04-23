#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

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
};

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
using namespace atcoder;
int op(int a, int b){ return max(a, b); }
int e(){ return 0; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    segtree<int, op, e> st(N + 1);
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> in(N + 1), out(N + 1), sz(N + 1), head(N + 1), son(N + 1), par(N + 1);
    int T = 0;
    function<void(int, int)> dfs0 = [&](int v, int p){
        sz[v] = 1;
        for (int to : adj[v]){
            if (to == p) continue;
            dfs0(to, v);
            sz[v] += sz[to];
            par[to] = v;
            if (sz[to] > sz[son[v]]) son[v] = to;
        }
    }; dfs0(1, 1);
    function<void(int, int, int)> dfs1 = [&](int v, int p, int h){
        in[v] = ++T;
        head[v] = h;
        if (son[v]) dfs1(son[v], v, h);
        for (int to : adj[v]){
            if (to == p || to == son[v]) continue;
            dfs1(to, v, to);
        }
        out[v] = T;
    }; dfs1(1, 1, 1);
    function<bool(int, int)> is = [&](int a, int b){
        return in[a] <= in[b] && out[a] >= out[b];
    };
    for (int i = 1; i <= N; ++i){
        st.set(in[i], a[i]);
    }
    for (int i = 1; i <= Q; ++i){
        int op; cin >> op;
        if (op == 1){
            int v, x; cin >> v >> x;
            a[v] = x;
            st.set(in[v], x);
        }
        if (op == 2){
            int a, b; cin >> a >> b;
            int ans = 0;
            while (!is(head[a], b)){
                ans = max(ans, st.prod(in[head[a]], in[a] + 1));
                a = par[head[a]];
            }
            while (head[b] != head[a]){
                ans = max(ans, st.prod(in[head[b]], in[b] + 1));
                b = par[head[b]];
            }
            if (is(b, a)) swap(a, b);
            ans = max(ans, st.prod(in[a], in[b] + 1));
            cout << ans << " ";
        }
    }
    cout << '\n';
}
