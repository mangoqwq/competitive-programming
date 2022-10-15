#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 1;

ll a[MN], v[MN], psa[MN], idx[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i] >> v[i];
    iota(idx + 1, idx + 1 + N, 1);
    sort(idx + 1, idx + 1 + N, [](ll i, ll j){ return a[i] < a[j]; });
    for (int i = 1; i <= N; ++i) psa[i] = psa[i - 1] + v[idx[i]];
    ll ans = 0, best = inf;
    for (int i = 1; i <= N; ++i){
        best = min(best, psa[i - 1] - a[idx[i]]);
        ans = max(ans, psa[i] - a[idx[i]] - best);
    }
    cout << ans << '\n';
}
