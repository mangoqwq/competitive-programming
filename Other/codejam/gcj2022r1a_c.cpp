#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

void solve(){
    int N, M; cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> c(N, vector<int>(N));
    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    for (int i = 0; i < N; ++i){
        for (int x = 0; x < M; ++x){
            int common = a[i][x];
            for (int j = i; j < N; ++j){
                common = min(common, a[j][x]);
                c[i][j] += common;
            }
        }
    }
    for (int i = 0; i < N; ++i) dp[i][i] = 2 * c[i][i];
    for (int sz = 1; sz < N; ++sz){
        for (int i = 0; i + sz < N; ++i){
            int j = i + sz;
            for (int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 2 * c[i][j]);
            }
        }
    }
    cout << dp[0][N - 1] << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
