#include <bits/stdc++.h>
 
using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MN = 2e5 + 1;
 
int N, L, R;
ll st[2 * MN], a[MN];
 
void upd(int i, ll val, int v = 1, int l = 0, int r = N){
    if (l == r) st[v] = val;
    else{
        if (i <= mid) upd(i, val, lc, l, mid);
        else upd(i, val, rc, mid + 1, r);
        st[v] = min(st[lc], st[rc]);
    }
}
 
ll qry(int ql, int qr, int v = 1, int l = 0, int r = N){
    if (r < ql || l > qr) return inf;
    if (l >= ql && r <= qr) return st[v];
    return min(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid + 1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> L >> R;
    ll ans = -inf;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        a[i] += a[i - 1];
        if (i >= L){
            ans = max(ans, a[i] - qry(max(i - R, 0), i - L));
        }
        upd(i, a[i]);
    }
    cout << ans << '\n';
}
