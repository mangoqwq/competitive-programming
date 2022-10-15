#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

struct BIT{
    ll a[MN];
    void upd(int i, ll v){ for (; i < MN; i += i & -i) a[i] += v; }
    ll qry(int i){
        ll ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
    ll qry(int l, int r){ return qry(r) - qry(l - 1); }
} bit[2];
ll a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        bit[i % 2].upd(i, a[i]);
    }
    while (Q--){
        int op, l, r; cin >> op >> l >> r;
        if (op == 1){
            bit[l % 2].upd(l, r - a[l]);
            a[l] = r;
        }
        else{
            cout << bit[l % 2].qry(l, r) << '\n';
        }
    }
}
