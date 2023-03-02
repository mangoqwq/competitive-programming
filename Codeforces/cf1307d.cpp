#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
using namespace atcoder;

int op(int a, int b){ return max(a, b); }
int e(){ return -1e9; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    vector<int> field(K);
    for (int i = 0; i < K; ++i){
        cin >> field[i];
        field[i]--;
    }

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto dijkstra = [&](int src) -> vector<int> {
        vector<int> dist(N, 1e9);
        dist[src] = 0;

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        while (!pq.empty()){
            auto [d, v] = pq.top(); pq.pop();
            if (d != dist[v]) continue;
            for (int to : adj[v]){
                if (dist[v] + 1 < dist[to]){
                    dist[to] = dist[v] + 1;
                    pq.push({dist[to], to});
                }
            }
        }
        return dist;
    };

    vector<int> da = dijkstra(0);
    vector<int> db = dijkstra(N-1);

    using pii = pair<int, int>;
    vector<pii> pts;
    for (int i = 0; i < K; ++i){
        pts.push_back({da[field[i]], db[field[i]]});
    }

    int lo = 0, hi = N;
    while (lo < hi){
        int mi = (lo + hi + 1) >> 1;
        bool ok = [&]() -> bool {
            segtree<int, op, e> st(N+1);
            for (auto [x, y] : pts){
                int needx = max(0, mi-x);
                int besty = st.prod(needx, N+1);
                if (besty + y >= mi) return 1;
                st.set(y, max(st.get(y), x));
            }
            return 0;
        }();
        // cout << mi << " " << ok << '\n';
        if (ok) lo = mi;
        else hi = mi - 1;
    }
    cout << min(da[N-1], lo+1) << '\n';
}
