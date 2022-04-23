#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
int dp[MN], p[MN], v[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    for (int i = 1; i <= N; ++i) cin >> p[i];
    for (int i = 1; i <= N; ++i) cin >> v[i];
    for (int i = 1; i <= N; ++i){
        for (int j = X; j >= p[i]; --j){
            dp[j] = max(dp[j], dp[j - p[i]] + v[i]);
        }
    }
    cout << dp[X] << '\n';
}
