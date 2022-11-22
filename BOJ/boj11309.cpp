#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int M = 32;
    vector<vector<ll>> dp(M+1, vector<ll>(M+1));
    for (int i = 1; i <= M; ++i){
        for (int j = 1; j <= M; ++j){
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1;
        }
    }
    int T; cin >> T;
    while (T--){
        ll N, K; cin >> N >> K;
        if (N > dp[K][M]) cout << "Impossible" << '\n';
        else{
            int ans = lower_bound(dp[K].begin(), dp[K].end(), N) - dp[K].begin();
            cout << ans << '\n';
        }
    }
}
