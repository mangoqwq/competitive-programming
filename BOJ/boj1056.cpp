#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

ll fpow(ll b, ll e){
    ll ret = 1;
    for (int i = 1; i <= e; ++i){
        double tmp = (double)ret * b;
        if (tmp > 2e18) return 2e18;
        ret = ret * b;
    }
    return ret;
}

unordered_map<ll, ll> dp;

ll bsearch(ll n, ll e){
    ll lo = 1, hi = 1e9, mid;
    while (lo < hi){
        mid = (lo + hi + 1) >> 1;
        if (fpow(mid, e) < n) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int solve(ll n){
    if (n == 1) return 0;
    if (dp.count(n)) return dp[n];
    dp[n] = n - 1;
    ll &ans = dp[n];
    ll lim = __lg(n) + 1;
    for (ll e = 2; e <= lim; ++e){
        ll lo = bsearch(n, e), hi = lo + 1;
        ll a = solve(lo) + n - fpow(lo, e);
        ll b = solve(hi) + fpow(hi, e) - n;
        ans = min({ans, a + 1, b + 1});
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    cout << solve(n) << '\n';
}
