#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

unordered_map<int, ll> dp;

ll solve(int n){
    if (dp[n]) return dp[n];
    for (int k = 2; k * k <= n; ++k){
        dp[n] += solve(n / k);
    }
    for (int k = 1; k < n / k; ++k){
        dp[n] += solve(k) * (n / k - n / (k + 1));
    }
    return dp[n];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    dp[1] = dp[2] = 1; dp[3] = 2;
    cout << solve(N) << '\n';
}
