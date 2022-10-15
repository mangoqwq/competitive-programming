#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, F; cin >> N >> F;
    vector<ll> h(N + 2), bad(N + 2, -inf);
    bad[N + 1] = 0;
    for (int i = 1; i <= N; ++i) cin >> h[i];
    for (int i = 1; i <= F; ++i){
        ll b, f; cin >> b >> f;
        bad[b] = max(bad[b], f);
    }
    struct Item{ int i; ll h; };
    vector<Item> stk = {{0, 0}};
    ll ans = 0;
    for (int i = 1; i <= N + 1; ++i){
        h[i] -= bad[i];
        if (h[i] > inf) continue;
        while (stk.size() > 1 && stk.back().h >= h[i]){
            auto [li, lh] = stk.back(); stk.pop_back();
            ans = max(ans, lh * (i - 1 - stk.back().i));
        }
        stk.push_back({i, h[i]});
    }
    cout << ans << '\n';
}
