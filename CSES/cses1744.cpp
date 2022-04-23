#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 501;
int dp[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            if (i == j) dp[i][j] = 0;
            else{
                dp[i][j] = inf;
                for (int k = 1; k < i; ++k){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k = 1; k < j; ++k){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }
    cout << dp[N][M] << '\n';
}
