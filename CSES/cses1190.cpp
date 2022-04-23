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
    ll tot, pre, suf, ans;
    Item() = default;
    Item(int x){
        tot = x;
        pre = suf = ans = max(x, 0);
    }
    friend Item merge(Item a, Item b){
        Item ret;
        ret.tot = a.tot + b.tot;
        ret.pre = max(a.pre, a.tot + b.pre);
        ret.suf = max(b.suf, b.tot + a.suf);
        ret.ans = max({a.suf + b.pre, a.ans, b.ans});
        return ret;
    }
} st[2 * MN];
void ins(int idx, Item val, int v = 1, int l = 1, int r = N){
    if (l == r) return void(st[v] = val);
    if (idx <= mid) ins(idx, val, lc, l, mid);
    else ins(idx, val, rc, mid + 1, r);
    st[v] = merge(st[lc], st[rc]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        int p; cin >> p;
        ins(i, Item(p));
    }
    while (Q--){
        int idx, val; cin >> idx >> val;
        ins(idx, Item(val));
        cout << st[1].ans << '\n';
    }
}
