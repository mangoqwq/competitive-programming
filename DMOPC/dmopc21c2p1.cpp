#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N, H, P; cin >> N >> H >> P;
    vector<ll> a(N);
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());
    ll cnt = N, cur = accumulate(a.begin(), a.end(), 0LL);
    ll ans = cur * P;
    for (ll x : a){
        ans = min(ans, x * H + (cur - cnt * x) * P);
        cur -= x; cnt--;
    }
    cout << ans << '\n';
}
