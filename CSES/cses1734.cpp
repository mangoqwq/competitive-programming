#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
map<int, int> seen;
int N, Q, a[MN];
vector<int> st[2 * MN];
void build(int v = 1, int l = 1, int r = N){
    if (l == r) st[v] = {a[l]};
    else{
        build(lc, l, mid); build(rc, mid + 1, r);
        st[v].resize(st[lc].size() + st[rc].size());
        merge(st[lc].begin(), st[lc].end(), st[rc].begin(), st[rc].end(), st[v].begin());
    }
}
ll qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr){
        return lower_bound(st[v].begin(), st[v].end(), ql) - st[v].begin();
    }
    return qry(ql, qr, lc, l, mid) + qry(ql, qr, rc, mid + 1, r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        a[i] = seen[x];
        seen[x] = i;
    }
    cout << '\n';
    build();
    while (Q--){
        int l, r; cin >> l >> r;
        cout << qry(l, r) << '\n';
    }
}
