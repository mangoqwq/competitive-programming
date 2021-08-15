#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

ll dp[MN], last[26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size(); s = "  " + s;
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n + 1; ++i){
        s[i] -= 'a';
        dp[i] = (dp[i - 2] - last[s[i]] + mod) % mod;
        last[s[i]] = dp[i - 2];
        dp[i] = (dp[i - 1] + dp[i]) % mod;
    }
    cout << dp[n + 1] - 1 << '\n';
}
