#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 301;

int dp[MN + 1][MN + 1];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int x, y; cin >> x >> y;
    ms(dp, inf);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        int a, b; cin >> a >> b;
        for (int i = MN - 1; i >= 0; --i){
            for (int j = MN - 1; j >= 0; --j){
                dp[i][j] = min({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
            }
        }
        for (int j = MN - 1; j >= a; --j){
            for (int k = MN - 1; k >= b; --k){
                dp[j][k] = min(dp[j][k], dp[j - a][k - b] + 1);
            }
        }
    }
    int mn = inf;
    for (int i = x; i <= MN - 1; ++i){
        for (int j = y; j <= MN - 1; ++j){
            mn = min(mn, dp[i][j]);
        }
    }
    if (mn == inf) cout << -1 << '\n';
    else cout << mn << '\n';
}
