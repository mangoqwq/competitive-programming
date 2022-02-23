#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;
int a[MN], pre[MN], suf[MN]; ll dp[MN], sufdp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    ms(dp, -0x3f),
    dp[0] = pre[0] = suf[0] = sufdp[0] = 0;
    int bl = 1, br = K;
    for (; bl <= N; bl += K, br += K){
        br = min(br, N);
        pre[bl] = a[bl];
        for (int i = bl + 1; i <= br; ++i) pre[i] = max(pre[i - 1], a[i]);
        for (int i = bl; i <= br; ++i){
            int j = max(i - K + 1, 1);
            dp[i] = max(pre[i] + dp[j - 1], sufdp[j - 1]);
        }
        suf[br] = a[br], sufdp[br] = dp[br];
        for (int i = br - 1; i >= bl; --i){
            sufdp[i] = max(sufdp[i + 1], dp[i] + suf[i + 1]);
            suf[i] = max(suf[i + 1], a[i]);
            dp[i] = max(dp[i], dp[i + 1]);
        }
    }
    cout << dp[N] << '\n';
}
