#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int mod = 1e9 + 7;
    int N, K; cin >> N >> K;
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= K; ++j) dp[i - 1][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        for (int j = 0; j <= K; ++j){
            dp[i][j] = (dp[i - 1][j] - (j <= i - 1 ? 0 : dp[i - 1][j - (i - 1) - 1]) + mod) % mod;
        }
    }
    cout << dp[N][K] << '\n';
}

