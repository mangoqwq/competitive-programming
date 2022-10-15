#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5010;

int a[MN];
int dp[MN][MN][2];

int cost(int a, int b){ return max(b - a + 1, 0); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    a[0] = a[N + 1] = -inf;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    ms(dp, 0x3f);
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; ++i){
        for (int k = 0; k <= N; ++k){
            // don't use
            dp[i][k][0] = min(dp[i - 1][k][0], dp[i - 1][k][1]);

            // use
            if (k == 0) continue;
            if (i == 1){
                dp[i][1][1] = cost(a[i], a[i + 1]);
            }
            else{
                dp[i][k][1] = min(dp[i - 2][k - 1][0] + cost(a[i], a[i - 1]) + cost(a[i], a[i + 1]),
                                  dp[i - 2][k - 1][1] + cost(a[i], min(a[i - 1], a[i - 2] - 1)) + cost(a[i], a[i + 1]));
            }
        }
    }
    for (int i = 1; i <= (N + 1) / 2; ++i){
        cout << min(dp[N][i][0], dp[N][i][1]) << " ";
    }
}
