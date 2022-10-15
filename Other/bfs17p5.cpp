#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;
const int all = (1 << 7) - 1;

int dp[MN], cnt[(1 << 7)][(1 << 7)], msk[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int K; cin >> K;
    for (int i = 0; i < K; ++i){
        int C; cin >> C;
        for (int j = 0; j < C; ++j){
            int x; cin >> x;
            msk[x] += (1 << i);
        }
    }
    for (int i = 1; i <= N; ++i){
        int lo = msk[i] >> 7;
        int hi = msk[i] % (1 << 7);
        int tmp = all - hi;
        for (int j = tmp; ; j = (j - 1) & tmp){
            dp[i] = (dp[i] + cnt[lo][j]) % mod;
            if (j == 0) break;
        }
        if (i == 1) dp[i] = 1;
        tmp = all - lo;
        for (int j = tmp; ; j = (j - 1) & tmp){
            cnt[j][hi] = (cnt[j][hi] + dp[i]) % mod;
            if (j == 0) break;
        }
    }
    cout << dp[N] << '\n';
}
