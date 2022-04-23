#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, Q, T;
struct Node{ int lc, rc; ll tot; } st[20 * MN];
int a[MN];
#define mid ((l + r) >> 1)
int build(int l = 1, int r = N){
    if (l == r) return st[++T] = {0, 0, a[l]}, T;
    int cur = ++T;
    st[cur].lc = build(l, mid);
    st[cur].rc = build(mid + 1, r);
    st[cur].tot = st[st[cur].lc].tot + st[st[cur].rc].tot;
    return cur;
}
int upd(int idx, int val, int v, int l, int r){
    if (l == r) return st[++T] = {0, 0, val}, T;
    int cur = ++T; st[cur] = st[v];
    if (idx <= mid) st[cur].lc = upd(idx, val, st[cur].lc, l, mid);
    else st[cur].rc = upd(idx, val, st[cur].rc, mid + 1, r);
    st[cur].tot = st[st[cur].lc].tot + st[st[cur].rc].tot;
    return cur;
}
ll qry(int ql, int qr, int v, int l, int r){
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return st[v].tot;
    return qry(ql, qr, st[v].lc, l, mid) + qry(ql, qr, st[v].rc, mid + 1, r);
}
vector<int> rts;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    rts.push_back(0);
    rts.push_back(build());
    for (int i = 1; i <= Q; ++i){
        int op; cin >> op;
        if (op == 1){
            int k, idx, val; cin >> k >> idx >> val;
            rts[k] = upd(idx, val, rts[k], 1, N);
        }
        if (op == 2){
            int k, l, r; cin >> k >> l >> r;
            cout << qry(l, r, rts[k], 1, N) << '\n';
        }
        if (op == 3){
            int k; cin >> k;
            rts.push_back(rts[k]);
        }
    }
}
