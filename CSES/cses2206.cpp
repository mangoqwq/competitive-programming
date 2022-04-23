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
struct Item{
    int mn, mx;
    friend Item merge(Item a, Item b){
        return {min(a.mn, b.mn), max(a.mx, b.mx)};
    }
} st[2 * MN];
void ins(int idx, Item val, int v = 1, int l = 1, int r = N){
    if (l == r) return void(st[v] = val);
    if (idx <= mid) ins(idx, val, lc, l, mid);
    else ins(idx, val, rc, mid + 1, r);
    st[v] = merge(st[lc], st[rc]);
}
Item qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    if (ql > r || qr < l) return {inf, -inf};
    if (l >= ql && r <= qr) return st[v];
    else return merge(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid + 1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        int p; cin >> p;
        ins(i, {p + i, i - p});
    }
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int idx, val; cin >> idx >> val;
            ins(idx, {val + idx, idx - val});
        }
        if (op == 2){
            int i; cin >> i;
            cout << min(qry(i, N).mn - i, i - qry(1, i).mx) << '\n';
        }
    }
}
