#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e3 + 1;
ll a[MN], dp[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i], a[i] += a[i - 1];
    for (int i = 1; i <= N; ++i) dp[i][i] = a[i] - a[i - 1];
    for (int sz = 2; sz <= N; ++sz){
        for (int i = 1; i + sz - 1 <= N; ++i){
            int j = i + sz - 1;
            dp[i][j] =  a[j] - a[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[1][N] << '\n';
}
