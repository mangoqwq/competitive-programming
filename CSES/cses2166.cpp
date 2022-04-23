#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, a[MN];
ll tot[2 * MN], pre[2 * MN];
void upd(int idx, int val, int v = 1, int l = 1, int r = N){
    if (l == r){
        pre[v] = tot[v] = val;
        return;
    }
    if (idx <= mid) upd(idx, val, lc, l, mid);
    else upd(idx, val, rc, mid + 1, r);
    tot[v] = tot[lc] + tot[rc];
    pre[v] = max(pre[lc], tot[lc] + pre[rc]);
}
pair<ll, ll> qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    if (ql > r || qr < l) return {0, 0};
    if (l >= ql && r <= qr) return {tot[v], pre[v]};
    pair<ll, ll> ansl = qry(ql, qr, lc, l, mid);
    pair<ll, ll> ansr = qry(ql, qr, rc, mid + 1, r);
    return {ansl.first + ansr.first, max(ansl.second, ansl.first + ansr.second)};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N; int Q; cin >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        upd(i, a[i]);
    }
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int idx, val; cin >> idx >> val;
            upd(idx, val);
        }
        if (op == 2){
            int a, b; cin >> a >> b;
            cout << max(0LL, qry(a, b).second) << '\n';
        }
    }
}
