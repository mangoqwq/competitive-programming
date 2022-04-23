#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, Q, st[2 * MN];
void upd(int idx, int val, int v = 1, int l = 1, int r = N){
    if (l == r) return void(st[v] = val);
    if (idx <= mid) upd(idx, val, lc, l, mid);
    else upd(idx, val, rc, mid + 1, r);
    st[v] = min(st[lc], st[rc]);
}

int qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    if (ql > r || qr < l) return inf;
    if (l >= ql && r <= qr) return st[v];
    return min(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid + 1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        upd(i, x);
    }
    while (Q--){
        int l, r; cin >> l >> r;
        cout << qry(l, r) << '\n';
    }
}
