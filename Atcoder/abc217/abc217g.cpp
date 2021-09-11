#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 998244353, inf = 0x3f3f3f3f;
const int MN = 5001;

ll dp[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * max(0, j - (i - 1) / M)) % mod;
        }
    }
    for (int i = 1; i <= N; ++i) cout << dp[N][i] << '\n';
}
