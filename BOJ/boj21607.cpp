#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e5 + 3, inf = 0x3f3f3f3f;
const int MN = 5e5 + 5;

template <ll (*f)(ll)>
struct Function{
    int N, layers;
    vector<vector<ll>> st;
    Function(){
        N = mod;
        layers = __lg((ll)5e5);
        st.assign(layers + 1, vector<ll>(N));
        for (int i = 0; i < N; ++i) st[0][i] = f(i);
        for (int i = 1; i <= layers; ++i)
            for (int j = 0; j < N; ++j)
                st[i][j] = st[i - 1][st[i - 1][j]];
    }
    ll operator()(ll x, ll p){
        ll ret = x;
        for (int i = layers; i >= 0; --i)
            if (1 & (p >> i)) ret = st[i][ret];
        return ret;
    }
};
struct Fenwick{
    ll a[MN];
    void ins(int i, ll val){ for (++i; i < MN; i += i & -i) a[i] += val; }
    void ins(int l, int r, ll val){ ins(l, val); ins(r + 1, -val); }
    ll qry(int i){
        ll ret = 0;
        for (++i; i; i -= i & -i) ret += a[i];
        return ret;
    }
} bitf, bitg;

ll a[MN];
ll fx(ll x){ return (2 * x * x - 1 + mod) % mod; }
ll gx(ll x){ return ((4 * x * x * x - 3 * x) % mod + mod) % mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    Function<fx> f;
    Function<gx> g;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; ++i){
        int op; cin >> op;
        if (op == 1){
            int l, r; cin >> l >> r;
            bitf.ins(l, r, 1);
        }
        if (op == 2){
            int l, r; cin >> l >> r;
            bitg.ins(l, r, 1);
        }
        if (op == 3){
            int i; cin >> i;
            ll cntf = bitf.qry(i);
            ll cntg = bitg.qry(i);
            cout << f(g(a[i], cntg), cntf) << '\n';
        }
    }
}
