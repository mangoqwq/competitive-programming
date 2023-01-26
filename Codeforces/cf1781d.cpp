#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        vector<vector<unordered_set<ll>>> dp(N, vector<unordered_set<ll>>(N));
        int ans = 0;
        for (int i = 0; i < N; ++i){
            for (int j = i-1; j >= 0; --j){
                ll d = a[i] - a[j];
                for (ll del = 1; del * del <= d; ++del){
                    ll t = (d - del*del) / 2 / del;
                    if (2 * t * del + del * del != d) continue;
                    for (int k = 1; k < N; ++k){
                        if (k >= 2 && dp[j][k-1].empty()) continue;
                        if ((k == 1 && a[j] <= t*t) || dp[j][k-1].count(t)){
                            dp[i][k].insert(t+del);
                            ans = max(ans, k);
                        }
                    }
                }
            }
        }
        cout << ans+1 << '\n';
    }
}
