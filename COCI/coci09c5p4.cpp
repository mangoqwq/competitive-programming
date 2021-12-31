#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define nxt(x) (x + 1 == K ? x : x + 1)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;
int a[MN], dp[MN][MN][5];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    ms(dp, 0x3f);
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        for (int k = 0; k < K; ++k){
            dp[i][i][k] = max(K - k - 1, 0);
        }
    }
    for (int len = 2; len <= N; ++len){
        for (int l = 1; l + len - 1 <= N; ++l){
            int r = l + len - 1;
            for (int k = K - 1; k >= 0; --k){
                int &cur = dp[l][r][k];
                cur = min(cur, dp[l][r][nxt(k)] + 1);
                cur = min(cur, dp[l][l][k] + dp[l + 1][r][0]);
                if (a[l] == a[l + 1]){
                    cur = min(cur, dp[l + 1][r][nxt(k)]);
                }
                for (int j = l + 2; j <= r; ++j){
                    if (a[l] == a[j]){
                        cur = min(cur, dp[l + 1][j - 1][0] + dp[j][r][nxt(k)]);
                    }
                }
            }
        }
    }
    cout << dp[1][N][0] << '\n';
}
