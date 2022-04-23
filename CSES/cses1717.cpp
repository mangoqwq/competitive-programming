#include <bits/stdc++.h>
 
using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    vector<ll> dp(N + 1);
    dp[0] = 1, dp[1] = 0;
    for (int i = 2; i <= N; ++i){
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << dp[N] << '\n';
}
