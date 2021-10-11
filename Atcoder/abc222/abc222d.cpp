#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 998244353, inf = 0x3f3f3f3f;
const int MN = 3001;

ll dp[MN][MN];
int l[MN], r[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 0; i < MN; ++i) dp[0][i] = 1;
    for (int i = 1; i <= N; ++i) cin >> l[i];
    for (int i = 1; i <= N; ++i) cin >> r[i];
    for (int i = 1; i <= N; ++i){
        for (int j = l[i]; j <= r[i]; ++j){
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
        for (int j = 1; j < MN; ++j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    }
    cout << dp[N][MN - 1] << '\n';
}
