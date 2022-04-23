#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, Q;
struct Node{
    ll tot, inc, lz;
} st[2 * MN];
ll a[MN];
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
void push(int v, int l, int r){
    if (st[v].lz == 0 && st[v].inc == 0) return;
    int sz = (r - l + 1);
    st[v].tot += st[v].inc * sz;
    st[v].tot += st[v].lz * (1LL * sz * (sz + 1)) / 2;
    if (l != r){
        st[lc].inc += st[v].inc;
        st[rc].inc += st[v].inc + st[v].lz * (mid + 1 - l);
        st[lc].lz += st[v].lz;
        st[rc].lz += st[v].lz;
    }
    st[v].lz = st[v].inc = 0;
}
void build(int v = 1, int l = 1, int r = N){
    if (l == r) return void(st[v] = {a[l], 0, 0});
    build(lc, l, mid), build(rc, mid + 1, r);
    st[v].tot = st[lc].tot + st[rc].tot;
}
void upd(int ql, int qr, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr){
        st[v].inc += l - ql;
        st[v].lz++;
        push(v, l, r);
        return;
    }
    upd(ql, qr, lc, l, mid), upd(ql, qr, rc, mid + 1, r);
    st[v].tot = st[lc].tot + st[rc].tot;
}
ll qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return st[v].tot;
    return qry(ql, qr, lc, l, mid) + qry(ql, qr, rc, mid + 1, r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    build();
    for (int i = 1; i <= Q; ++i){
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) upd(a, b);
        if (op == 2) cout << qry(a, b) << '\n';
    }
}
