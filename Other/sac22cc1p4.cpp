#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;

ll dp[MN][4];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    dp[0][0] = 1;
    int N; cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        for (int k = 3; k >= 1; --k){
            for (int j = a; j <= 100; ++j){
                dp[j][k] += dp[j - a][k - 1];
            }
        }
        ans = ans + dp[a][3];
    }
    cout << ans << '\n';
}
