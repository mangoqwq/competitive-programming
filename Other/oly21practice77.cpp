#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2501;

ll dp[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        for (int j = N; j >= 1; --j){
            for (int k = 2500; k >= a; --k){
                dp[j][k] += dp[j - 1][k - a];
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i * X <= 2500 && i <= N; ++i){
        ans += dp[i][i * X];
    }
    cout << ans << '\n';
}
