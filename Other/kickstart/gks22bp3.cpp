#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int N, D; cin >> N >> D;
    vector<ll> a(N + 1);
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(2, 1e18)));
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        dp[i][i][0] = dp[i][i][1] = 0;
    }
    function<ll(ll, ll)> dist = [&](ll a, ll b){
        ll tmp = (a - b + D) % D;
        return min(tmp, D - tmp);
    };
    for (int sz = 2; sz <= N; ++sz){
        for (int i = 1; i + sz - 1 <= N; ++i){
            int l = i, r = i + sz - 1;
            dp[l][r][0] = min(dp[l + 1][r][0] + dist(a[l], a[l + 1]),
                              dp[l + 1][r][1] + dist(a[l], a[r]));
            dp[l][r][1] = min(dp[l][r - 1][0] + dist(a[r], a[l]),
                              dp[l][r - 1][1] + dist(a[r], a[r - 1]));
        }
    }
    cout << min(dp[1][N][0] + dist(0, a[1]), dp[1][N][1] + dist(0, a[N])) << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
