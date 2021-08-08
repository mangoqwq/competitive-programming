#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 998244353, inf = 0x3f3f3f3f;
const int MN = 17;

ll p2[MN], cnt[1 << MN], dp[1 << MN], noton[1 << MN];
struct Edge{ int a, b; };
vector<Edge> edges;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        edges.push_back({--a, --b});
    }
    p2[0] = 1;
    for (int i = 1; i <= M; ++i) p2[i] = p2[i - 1] * 2 % mod;
    const int all = (1 << N) - 1;
    for (int i = 0; i <= all; ++i){
        for (auto [a, b] : edges){
            int ba = (1 & (i >> a));
            int bb = (1 & (i >> b));
            if (ba && bb) cnt[i]++;
        }
    }
    for (int i = 0; i <= all; ++i){
        dp[i] = p2[cnt[i]];
        int x = __builtin_ffs(i) - 1;
        for (int j = i; j; j = (j - 1) & i){
            if (j == i || !(1 & (j >> x))) continue;
            dp[i] -= dp[j] * p2[cnt[i - j]] % mod;
        }
        dp[i] = (dp[i] % mod + mod) % mod;
    }
    for (int i = 1; i < N; ++i){
        ll ans = 0;
        for (int mask = 0; mask < (1 << N); ++mask){
            if (!(1 & (mask >> 0)) || !(1 & (mask >> i))) continue;
            ans += dp[mask] * p2[cnt[all - mask]] % mod;
        }
        ans = ans % mod;
        cout << ans << '\n';
    }
}
