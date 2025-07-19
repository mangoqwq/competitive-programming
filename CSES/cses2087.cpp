#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<ll> c(N);
    for (int i = 0; i < N; ++i){
        cin >> c[i];
    }
 
    vector<ll> cnt(N + 1), lef(N + 1), rig(N + 1);
    for (int i = 0; i < N; ++i){
        cnt[i + 1] = cnt[i] + c[i];
        lef[i + 1] = lef[i] + c[i] * (N - i);
        rig[i + 1] = rig[i] + c[i] * i;
    }
 
    vector<vector<ll>> sum_rig(N + 1, vector<ll>(N + 1));
    vector<vector<ll>> sum_lef(N + 1, vector<ll>(N + 1));
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= N; ++j){
            sum_rig[i][j] = (rig[j] - rig[i]) - (cnt[j] - cnt[i]) * (i);
            sum_lef[i][j] = (lef[j] - lef[i]) - (cnt[j] - cnt[i]) * (N - j + 1);
        }
    }
 
    vector<vector<ll>> dp(K + 1, vector<ll>(N, 1e18));
    function<void(int, int, int, int, int)> solve = [&](int k, int l, int r, int ql, int qr){
        if (l == r) return;
        int i = (l + r) >> 1;
        int opt = -1;
        for (int j = ql; j < min(i, qr); ++j){
            int m = (j + i + 1) >> 1;
            ll val = (j == 0 ? 0 : dp[k - 1][j]) + sum_rig[j][m] + sum_lef[m][i + 1];
            if (val < dp[k][i]){
                dp[k][i] = val;
                opt = j;
            }
        }
        solve(k, l, i, ql, opt + 1);
        solve(k, i + 1, r, opt, qr);
    };
 
    for (int i = 0; i < N; ++i){
        dp[1][i] = sum_lef[0][i + 1];
    }
    for (int k = 2; k <= K; ++k){
        solve(k, 0, N, 0, N);
    }
 
    ll ans = 1e18;
    for (int i = 0; i < N; ++i){
        ans = min(ans, dp[K][i] + sum_rig[i][N]);
    }
    cout << ans << '\n';
}
