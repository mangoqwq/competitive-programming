#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

}  // namespace atcoder
using namespace atcoder;

int op(int a, int b){ return min(a, b); }
int e(){ return 1e9; }
int mapping(int a, int b){ return a+b; }
int composition(int a, int b){ return a+b; }
int id(){ return 0; }

struct Rect{ int x1, x2, y1, y2; };

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--){
        int N; cin >> N;
        vector<Rect> rects(N);
        map<int, int> comp;
        map<int, int> decomp;
        for (int i = 0; i < N; ++i){
            cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
            rects[i].y2++;
            comp[rects[i].y1] = 0;
            comp[rects[i].y2] = 0;
        }
        int T = 0;
        for (auto [a, b] : comp){
            decomp[T] = a;
            comp[a] = T++;
        }
        for (int i = 0; i < N; ++i){
            rects[i].y1 = comp[rects[i].y1];
            rects[i].y2 = comp[rects[i].y2];
        }

        using seg = lazy_segtree<int, op, e, int, mapping, composition, id>;
        vector<seg> st(2, seg(T));
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < T; ++j){
                st[i].set(j, 0);
            }
        }
        for (int i = 0; i < N; ++i){
            for (int x = rects[i].x1; x <= rects[i].x2; ++x){
                st[x-1].apply(rects[i].y1, rects[i].y2, 1);
            }
        }
        for (int i = 0; i < N; ++i){
            int least = 1e9;
            for (int x = rects[i].x1; x <= rects[i].x2; ++x){
                least = min(least, st[x-1].prod(rects[i].y1, rects[i].y2));
            }
            if (least >= 2){
                for (int x = rects[i].x1; x <= rects[i].x2; ++x){
                    st[x-1].apply(rects[i].y1, rects[i].y2, -1);
                }
                rects[i] = {0, 0, 0, 0};
            }
        }

        vector<vector<int>> far(2, vector<int>(T));
        for (int i = 0; i < N; ++i){
            if (rects[i].x1 && rects[i].x1 == rects[i].x2){
                far[rects[i].x1 - 1][rects[i].y1] = max(far[rects[i].x1 - 1][rects[i].y1], rects[i].y2);
            }
        }
        vector<vector<int>> pfar(2, vector<int>(T+1));
        pfar[0][0] = far[0][0];
        pfar[1][0] = far[1][0];
        for (int i = 1; i <= T; ++i){
            pfar[0][i] = max(pfar[0][i-1], far[0][i-1]);
            pfar[1][i] = max(pfar[1][i-1], far[1][i-1]);
        }
        vector<int> ord(N); iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){
            return rects[i].y1 < rects[j].y1;
        });

        vector<int> block;
        int upto = -1e9;
        for (int _ = 0; _ < N; ++_){
            int i = ord[_];
            if (rects[i].x1 != rects[i].x2){
                bool c0 = pfar[0][rects[i].y1+1] >= rects[i].y2;
                bool c1 = pfar[1][rects[i].y1+1] >= rects[i].y2;
                if (c0 && c1) rects[i] = {0, 0, 0, 0};
                else if (c0) rects[i] = {2, 2, rects[i].y1, rects[i].y2};
                else if (c1) rects[i] = {1, 1, rects[i].y1, rects[i].y2};
                else{
                    rects[i].y1 = max(rects[i].y1, upto);
                    upto = rects[i].y2;
                    block.push_back(i);
                }
            }
        }

        for (int x = 1; x <= 2; ++x){
            int upto = -1e9;
            for (int _ = 0; _ < N; ++_){
                int i = ord[_];
                if (rects[i].x1 == x && rects[i].x2 == x){
                    rects[i].y1 = max(rects[i].y1, upto);
                    upto = rects[i].y2;
                }
            }
        }

        vector<vector<int>> vis(2, vector<int>(T));
        auto fill = [&](int i){
            for (int x = rects[i].x1; x <= rects[i].x2; ++x){
                for (int y = rects[i].y1; y < rects[i].y2; ++y){
                    vis[x-1][y] = 1;
                }
            }
        };
        for (int i = 0; i < N; ++i){
            if (rects[i].x1 == 1 && rects[i].x2 == 2){
                fill(i);
            }
        }
        for (int i = 0; i < N; ++i){
            int x = rects[i].x1;
            if (x && rects[i].x1 == rects[i].x2){
                while (vis[x-1][rects[i].y1]) rects[i].y1++;
                while (vis[x-1][rects[i].y2-1]) rects[i].y2--;
            }
            fill(i);
        }

        ll area = 0;
        for (int i = 0; i < N; ++i){
            if (!rects[i].x1) continue;
            rects[i].y1 = decomp[rects[i].y1];
            rects[i].y2 = decomp[rects[i].y2];
            rects[i].y2--;
            area += (rects[i].x2 - rects[i].x1 + 1) * (rects[i].y2 - rects[i].y1 + 1);
        }
        cout << area << '\n';
        for (int i = 0; i < N; ++i){
            cout << rects[i].x1 << " " << rects[i].y1 << " " << rects[i].x2 << " " << rects[i].y2 << '\n';
        }
    }
}
