#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

ll dp[3][MN];
ll v[3][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int k = 0; k <= 2; ++k){
        for (int i = 1; i <= N; ++i) cin >> v[k][i];
        sort(v[k] + 1, v[k] + 1 + N);
        if (k == 0){
            for (int i = 1; i <= N; ++i) dp[k][i] = i;
        }
        else{
            for (int i = 1; i <= N; ++i){
                dp[k][i] = dp[k - 1][lower_bound(v[k - 1] + 1, v[k - 1] + 1 + N, v[k][i]) - v[k - 1] - 1];
            }
            for (int i = 1; i <= N; ++i) dp[k][i] += dp[k][i - 1];
        }
    }
    cout << dp[2][N] << '\n';
}
