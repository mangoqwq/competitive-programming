#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, S; cin >> N >> S;
    vector<vector<int>> dp(N+1, vector<int>(2000));
    vector<int> w, v;
    for (int i = 2; i <= N; ++i){
        int c = (i-1) * (i-2) / 2;
        dp[i][c] = 1;
        w.push_back(i-2);
        v.push_back(c);
    }
    for (int i = 0; i < w.size(); ++i){
        for (int j = w[i]; j <= N; ++j){
            for (int k = v[i]; k <= S; ++k){
                dp[j][k] |= dp[j - w[i]][k - v[i]];
            }
        }
    }
    cout << dp[N][S] << '\n';
}
