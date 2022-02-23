#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 1;

int N;
struct Item{
    long double val; ll ans;
    Item(){
        val = 0;
        ans = 1;
    }
    Item(int x){
        val = logl(x);
        ans = x;
    }
    Item(double val, ll ans){
        this->val = val;
        this->ans = ans;
    }
    void apply(const Item &other){
        val += other.val;
        ans = (ans * other.ans) % mod;
    }
} st[2 * MN], lz[2 * MN];

void push(int v, int l, int r){
    if (abs(lz[v].val) < 1e-15) return;
    st[v].apply(lz[v]);
    if (l != r){
        lz[lc].apply(lz[v]);
        lz[rc].apply(lz[v]);
    }
    lz[v] = Item(1);
}
void upd(int ql, int qr, Item val, int v = 1, int l = 0, int r = N - 1){
    push(v, l, r);
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr){ lz[v] = val, push(v, l, r); return; }
    upd(ql, qr, val, lc, l, mid); upd(ql, qr, val, rc, mid + 1, r);
    st[v] = st[lc].val > st[rc].val ? st[lc] : st[rc];
}

ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}
ll inv(int x){ return fpow(x, mod - 2); }

ll X[MN], Y[MN];

int calc(){ return st[1].ans; }

int updateX(int pos, int val){
    upd(pos, N - 1, Item(-logl(X[pos]), inv(X[pos])));
    X[pos] = val;
    upd(pos, N - 1, Item(X[pos]));
    return calc();
}

int updateY(int pos, int val){
    upd(pos, pos, Item(-logl(Y[pos]), inv(Y[pos])));
    Y[pos] = val;
    upd(pos, pos, Item(Y[pos]));
    return calc();
}

int init(int _N, int _X[], int _Y[]){
    N = _N;
    for (int i = 0; i < N; ++i){
        X[i] = _X[i];
        upd(i, N - 1, Item(X[i]));
        Y[i] = _Y[i];
        upd(i, i, Item(Y[i]));
    }
    return calc();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N = 3;
    int X[] = {2, 1, 3};
    int Y[] = {3, 4, 1};
    cout << init(N, X, Y) << '\n';
}
