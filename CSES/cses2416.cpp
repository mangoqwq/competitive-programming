#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, Q;
struct Node{ int mn1, mn2, cntmn, lz; ll tot; } st[2 * MN];
Node merge(Node a, Node b){
    Node ret;
    ret.tot = a.tot + b.tot;
    ret.lz = 0;
    if (a.mn1 == b.mn1){
        ret.mn1 = a.mn1;
        ret.cntmn = a.cntmn + b.cntmn;
        ret.mn2 = min(a.mn2, b.mn2);
    }
    else if (a.mn1 < b.mn1){
        ret.mn1 = a.mn1;
        ret.cntmn = a.cntmn;
        ret.mn2 = min(a.mn2, b.mn1);
    }
    else{
        ret.mn1 = b.mn1;
        ret.cntmn = b.cntmn;
        ret.mn2 = min(a.mn1, b.mn2);
    }
    return ret;
}
void push(int v, int l, int r){
    if (!st[v].lz) return;
    if (st[v].lz <= st[v].mn1){
        st[v].lz = 0;
        return;
    }
    st[v].tot += 1LL * st[v].cntmn * (st[v].lz - st[v].mn1);
    st[v].mn1 = st[v].lz;
    if (l != r){
        st[lc].lz = st[v].lz;
        st[rc].lz = st[v].lz;
        push(v, l, r);
    }
    st[v].lz = 0;
}
void build(int v = 1, int l = 1, int r = N){
    if (l == r) st[v] = {0, inf, 1, 0, 0};
    else{
        build(lc, l, mid); build(rc, mid + 1, r);
        st[v] = merge(st[lc], st[rc]);
    }
}
void chmax(int ql, int qr, int val, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr || r < ql || val <= st[v].mn1) return;
    if (l >= ql && r <= qr && val < st[v].mn2){
        st[v].lz = val;
        push(v, l, r);
    }
    else{
        chmax(ql, qr, val, lc, l, mid), chmax(ql, qr, val, rc, mid + 1, r);
        st[v] = merge(st[lc], st[rc]);
    }
}
ll qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return st[v].tot;
    else return qry(ql, qr, lc, l, mid) + qry(ql, qr, rc, mid + 1, r);
}
ll qrymn2(int ql, int qr, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr || r < ql) return inf;
    if (l >= ql && r <= qr) return cout << st[v].mn2 << " ", st[v].mn2;
    else return min(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid + 1, r));
}
struct Fenwick{
    ll a[MN];
    void ins(int i, int v){ for (; i < MN; i += i & -i) a[i] += v; }
    ll qry(int i){
        ll ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
} bit;

int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    build();
    for (int i = 1; i <= N; ++i) cin >> a[i];
    struct Query{ int l, r, id; };
    vector<Query> qs; vector<ll> ans(Q);
    for (int i = 0; i < Q; ++i){
        int l, r; cin >> l >> r;
        qs.push_back({l, r, i});
    }
    sort(qs.begin(), qs.end(), [](Query a, Query b){ return a.l < b.l; });
    reverse(qs.begin(), qs.end());
    int p = N;
    for (auto [l, r, id] : qs){
        while (p >= l && p > 0){
            bit.ins(p, a[p]);
            chmax(p, N, a[p]);
            p--;
        }
        ans[id] = qry(l, r) - bit.qry(r);
    }
    for (ll x : ans) cout << x << '\n';
}
