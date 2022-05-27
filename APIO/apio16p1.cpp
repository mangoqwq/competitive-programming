#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N + 1), b(N + 1);
    vector<int> comp;
    for (int i = 1; i <= N; ++i){
        cin >> a[i] >> b[i]; a[i]--;
        comp.push_back(a[i]);
        comp.push_back(b[i]);
    }
    comp.push_back(0);
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for (int i = 1; i <= N; ++i){
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
        b[i] = lower_bound(comp.begin(), comp.end(), b[i]) - comp.begin();
    }

    int M = comp.size();
    vector<vector<ll>> table(M, vector<ll>(N + 1));
    for (int i = 1; i < M; ++i){
        ll sz = comp[i] - comp[i - 1];
        table[i][1] = sz;
        for (int j = 2; j <= N; ++j){
            table[i][j] = table[i][j - 1] * (sz + j - 1) % mod * fpow(j, mod - 2) % mod;
        }
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(M, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 1; i <= N; ++i){
        int l = a[i] + 1;
        int cnt = 1;
        while (l != b[i] + 1){
            int cnt = 1;
            for (int j = i - 1; j >= 0; --j){
                dp[i][l] = (dp[i][l] + table[l][cnt] * dp[j][l - 1]) % mod;
                if (a[j] < l && l <= b[j]){
                    cnt++;
                }
            }
            l++;
        }
        for (int j = 1; j < M; ++j){
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; ++i){
        ans += dp[i][M - 1];
        ans %= mod;
    }
    cout << ans << '\n';
}
