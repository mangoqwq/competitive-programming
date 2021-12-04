#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 4e5 + 1;

int N, Q;
int pre[MN], suf[MN], ans[MN], a[MN];
void upd(int idx, int val, int v = 1, int l = 1, int r = N - 1){
    if (l == r){ pre[v] = suf[v] = ans[v] = val; }
    else{
        if (idx <= mid) upd(idx, val, lc, l, mid);
        else upd(idx, val, rc, mid + 1, r);
        pre[v] = pre[lc];
        if (ans[lc] == (mid - l + 1)) pre[v] = ans[lc] + pre[rc];
        suf[v] = suf[rc];
        if (ans[rc] == (r - (mid + 1) + 1)) suf[v] = ans[rc] + suf[lc];
        ans[v] = max({ans[lc], ans[rc], suf[lc] + pre[rc]});
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= Q; ++i){
        int idx; cin >> idx;
        a[idx] ^= 1;
        if (idx != 1) upd(idx - 1, a[idx] != a[idx - 1]);
        if (idx != N) upd(idx, a[idx] != a[idx + 1]);
        cout << ans[1] + 1 << '\n';
    }
}
