#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

mt19937 gen;
uniform_int_distribution<ll> dis(0, 4e18);
// generate random [0, r)
ll ran(ll r){ return dis(gen) % r;}

ll ask(ll x){
    cout << x << '\n';
    cout.flush();
    ll ret; cin >> ret;
    if (ret == -1) exit(0);
    return ret;
}

void solve(){
    ll n = ask(0);
    if (n == 0) return;
    if (n == 1){ ask(1); return; }
    n--;
    ll ans = 1LL << n;
    for (int i = n - 1; i >= 0;){
        ll add = ran(1LL << (i + 1));
        assert(add >= 0);
        ans += add;
        i = ask(ans) / 2 - 1;
        if (i == -1) return;
        ans ^= (1LL << i);
        if (i == 0) break;
        ans -= ans % (1LL << i);
        i--;
    }
    ask(ans);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        solve();
        // cout << ran(1e18) << " ";
    }
}
