#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 998244353, inf = 0x3f3f3f3f;
const int MN = 35, MK = 35, MM = 105;

// dp[i][nums used][number 1s][carry] = total sum
ll dp[MM][MN][MK][MK], fact[MN], finv[MN], pws[MN];
ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}
ll inv(ll x){ return fpow(x, mod - 2); }
ll choose(int n, int k){ return fact[n] * finv[k] % mod * finv[n - k] % mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    fact[0] = finv[0] = 1;
    for (int i = 1; i <= N; ++i){
        fact[i] = fact[i - 1] * i % mod;
        finv[i] = inv(fact[i]);
    }
    vector<int> v(M + 1);
    cin >> v[0];
    for (int j = 0; j <= N; ++j){
        dp[0][j][j & 1][j >> 1] = choose(N, j) * fpow(v[0], j) % mod;
    }
    for (int i = 1; i <= M; ++i){
        cin >> v[i];
        pws[0] = 1;
        for (int j = 1; j <= N; ++j) pws[j] = pws[j - 1] * v[i] % mod;
        for (int j = 0; j <= N; ++j){
            for (int k = 0; k <= K; ++k){
                for (int c = 0; c < MK; ++c){
                    for (int u = 0; u + j <= N; ++u){
                        ll &cur = dp[i][u + j][k + ((u + c) & 1)][(u + c) >> 1];
                        ll lst = dp[i - 1][j][k][c];
                        cur = (cur + lst * choose(N - j, u) % mod * pws[u]) % mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= K; ++k){
        for (int c = 0; c < MK; ++c){
            if (k + __builtin_popcount(c) <= K){
                ans = (ans + dp[M][N][k][c]) % mod;
            }
        }
    }
    cout << ans << '\n';
}
