#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Function{
    ll m, b;
    ll operator()(ll x){
        return m * x + b;
    }
};

struct Lichao{

#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))

    int N;
    vector<Function> st;

    Lichao(int N) : N(N){
        st.assign(2 * N, Function{(ll)1e12, (ll)1e12});
    }

    void insert(Function f, int v, int l, int r){
        bool cl = f(l) < st[v](l);
        bool cm = f(mid) < st[v](mid);
        if (cm) swap(f, st[v]);
        if (l == r) return;
        if (cl != cm) insert(f, lc, l, mid);
        else insert(f, rc, mid + 1, r);
    }
    void insert(Function f){ insert(f, 1, 0, N - 1); }

    ll query(int x, int v, int l, int r){
        if (l == r) return st[v](x);
        if (x <= mid) return min(st[v](x), query(x, lc, l, mid));
        else return min(st[v](x), query(x, rc, mid + 1, r));
    }
    ll query(int x){ return query(x, 1, 0, N - 1); }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, si; cin >> N >> si;
    vector<int> s(N), f(N);
    for (int i = 0; i < N; ++i){
        cin >> s[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> f[i];
    }

    Lichao lct(1e6 + 1);
    lct.insert(Function{si, 0});
    vector<ll> dp(N);
    for (int i = 0; i < N; ++i){
        dp[i] = lct.query(s[i]);
        lct.insert({f[i], dp[i]});
    }
    cout << dp[N - 1] << '\n';
}
