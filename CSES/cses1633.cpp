#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;
int dp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    dp[0] = 1;
    for (int i = 1; i <= N; ++i){
        for (int j = max(0, i - 6); j < i; ++j){
            dp[i] = (dp[i] + dp[j]) % mod;
        }
    }
    cout << dp[N] << '\n';
}
