#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 20;

int w[MN];
pair<int, int> dp[1 << MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    for (int i = 0; i < N; ++i) cin >> w[i];
    ms(dp, 0x3f);
    dp[0] = {1, 0};
    for (int i = 0; i < (1 << N); ++i){
        for (int j = 0; j < N; ++j){
            if (!(1 & (i >> j))) continue;
            pair<int, int> lst = dp[i - (1 << j)];
            if (lst.second + w[j] > X){
                dp[i] = min(dp[i], {lst.first + 1, w[j]});
            }
            else{
                dp[i] = min(dp[i], {lst.first, lst.second + w[j]});
            }
        }
    }
    cout << dp[(1 << N) - 1].first << '\n';
}
