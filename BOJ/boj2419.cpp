#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    a.push_back(0);
    sort(a.begin(), a.end());
    int s = lower_bound(a.begin(), a.end(), 0) - a.begin();
    N = a.size();
    ll best = 0;
    vector<vector<vector<ll>>> dp(N+1,
        vector<vector<ll>>(N+1, vector<ll>(2, 0)));
    for (int L = 1; L < N; ++L){
        dp[s][s][0] = dp[s][s][1] = L*M;
        for (int l = s; l >= max(0, s-L); --l){
            for (int r = s; r < min(N, l+L+1); ++r){
                if (l == r) continue;
                int c = r-l;
                dp[l][r][0] = max(dp[l+1][r][1] - (L-c+1) * (a[r]-a[l]), dp[l+1][r][0] - (L-c+1) * (a[l+1]-a[l]));
                dp[l][r][1] = max(dp[l][r-1][1] - (L-c+1) * (a[r]-a[r-1]), dp[l][r-1][0] - (L-c+1) * (a[r]-a[l]));
                if (c == L){
                    best = max({best, dp[l][r][0], dp[l][r][1]});
                }
            }
        }
    }
    cout << best << '\n';
}
