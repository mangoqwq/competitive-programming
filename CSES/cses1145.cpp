#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
int dp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        int j = lower_bound(dp, dp + ans + 1, x) - dp;
        ans = max(ans, j);
        dp[j] = x;
    }
    cout << ans << '\n';
}
