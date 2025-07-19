#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<ll> a(N + 1), psa(N + 1);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i){
        psa[i + 1] = psa[i] + a[i];
    }
 
    vector<vector<ll>> dp(N + 1, vector<ll>(N, 1e18));
    vector<vector<ll>> opt(N + 1, vector<ll>(N));
    for (int i = 0; i < N; ++i){
        dp[i][i] = 0;
        opt[i][i] = i;
    }
    for (int len = 2; len <= N; ++len){
        for (int l = 0; l + len - 1 < N; ++l){
            int r = l + len - 1;
#pragma GCC ivdep
            for (int i = opt[l][r - 1]; i <= opt[l + 1][r]; ++i){
                ll c = dp[l][i] + dp[i + 1][r] + psa[r + 1] - psa[l];
                if (c < dp[l][r]){
                    dp[l][r] = c;
                    opt[l][r] = i;
                }
            }
        }
    }
    cout << dp[0][N - 1] << '\n';
}
