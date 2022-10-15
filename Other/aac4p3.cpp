#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

ll x[MN], y[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    set<pair<ll, ll>> seen;
    for (int i = 1; i <= M; ++i){
        ll k, d; cin >> k >> d;
        int g = gcd(k, d);
        k /= g;
        d /= g;
        if (d < 0) k *= -1, d *= -1;
        if (seen.count({k, d})) continue;
        seen.insert({k, d});
        map<ll, ll> cnt;
        for (int j = 1; j <= N; ++j){
            ll cur = y[j] * d - x[j] * k;
            ans += cnt[cur]++;
        }
    }
    cout << ans << '\n';
}
