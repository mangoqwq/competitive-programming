#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 998244353, inf = 0x3f3f3f3f;
const int MN = 402;

ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}
ll fact[MN], inv[MN];
ll choose(ll n, ll k){ return fact[n] * inv[k] % mod * inv[n - k] % mod; }
ll dp[MN][MN], tot[MN][MN];
set<int> adj[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M; N = N * 2;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
    }
    fact[1] = inv[1] = 1;
    for (int i = 2; i <= N; ++i){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = fpow(fact[i], mod - 2);
    }
    for (int i = 1; i <= N; ++i) tot[i][i] = 1;
    for (int sz = 2; sz <= N; sz += 2){
        for (int l = 1; l + sz - 1 <= N; ++l){
            int r = l + sz;
            if (adj[l].count(r - 1)) dp[l][r] = tot[l + 1][r - 1];
            tot[l][r] = dp[l][r];
            for (int i = l + 2; i <= r - 2; ++i){
                int sz1 = i - l; sz1 >>= 1;
                int sz2 = r - i; sz2 >>= 1;
                tot[l][r] = (tot[l][r] + dp[l][i] * tot[i][r] % mod * choose(sz1 + sz2, sz1) % mod) % mod;
            }
        }
    }
    cout << tot[1][N + 1] << '\n';
}
