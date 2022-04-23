#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, Q;

#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
struct Node{ ll tot, inc, eq; } st[2 * MN];
void push(int v, int l, int r){
    if (st[v].eq){
        st[v].tot = 1LL * (r - l + 1) * st[v].eq;
        if (l != r){
            st[lc].eq = st[v].eq; 
            st[lc].inc = 0;
            st[rc].eq = st[v].eq;
            st[rc].inc = 0;
        }
        st[v].eq = 0;
    }
    if (st[v].inc){
        st[v].tot += 1LL * (r - l + 1) * st[v].inc;
        if (l != r){
            st[lc].inc += st[v].inc;
            st[rc].inc += st[v].inc;
        }
        st[v].inc = 0;
    }
}
ll qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr ||r < ql) return 0;
    if (l >= ql && r <= qr) return st[v].tot;
    return qry(ql, qr, lc, l, mid) + qry(ql, qr, rc, mid + 1, r);
}
void inc(int ql, int qr, int val, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr ||r < ql) return;
    if (l >= ql && r <= qr) st[v].inc += val, push(v, l, r);
    else{
        inc(ql, qr, val, lc, l, mid), inc(ql, qr, val, rc, mid + 1, r);
        st[v].tot = st[lc].tot + st[rc].tot;
    }
}
void eq(int ql, int qr, int val, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr ||r < ql) return;
    if (l >= ql && r <= qr) st[v].eq = val, st[v].inc = 0, push(v, l, r);
    else{
        eq(ql, qr, val, lc, l, mid), eq(ql, qr, val, rc, mid + 1, r);
        st[v].tot = st[lc].tot + st[rc].tot;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        eq(i, i, a);
    }
    for (int i = 1; i <= Q; ++i){
        int op; cin >> op;
        if (op == 1){
            int a, b, x; cin >> a >> b >> x;
            inc(a, b, x);
        }
        if (op == 2){
            int a, b, x; cin >> a >> b >> x;
            eq(a, b, x);
        }
        if (op == 3){
            int a, b; cin >> a >> b;
            cout << qry(a, b) << '\n';
        }
    }
}
