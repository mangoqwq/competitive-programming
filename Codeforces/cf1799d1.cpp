#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        vector<ll> cold(K+1), hot(K+1);
        for (int i = 1; i <= K; ++i){
            cin >> cold[i];
        }
        for (int i = 1; i <= K; ++i){
            cin >> hot[i];
        }

        vector<ll> dp(K+2, 1e18);
        dp[K+1] = cold[a[0]];
        for (int i = 1; i < N; ++i){
            vector<ll> nxt(K+2, 1e18);
            for (int j = 1; j <= K+1; ++j){
                nxt[j] = min(nxt[j], dp[j] + (a[i] == a[i-1] ? hot[a[i]] : cold[a[i]]));
            }
            for (int j = 1; j <= K+1; ++j){
                nxt[a[i-1]] = min(nxt[a[i-1]], dp[j] + (a[i] == j ? hot[a[i]] : cold[a[i]]));
            }
            swap(dp, nxt);
        }
        cout << *min_element(dp.begin(), dp.end()) << '\n';
    }
}
