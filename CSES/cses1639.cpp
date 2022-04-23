#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e3 + 1;
int dp[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int N = s.size(), M = t.size();
    s = " " + s; t = " " + t;
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= M; ++j){
            if (!i || !j) dp[i][j] = max(i, j);
            else{
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i] != t[j]));
            }
        }
    }
    cout << dp[N][M] << '\n';
}
