#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = (1 << 22);

ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}
int cnt[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= M; ++i){
        int msk; cin >> msk;
        cnt[msk]++;
    }
    for (int i = 0; i < N; ++i){
        for (int msk = 0; msk < (1 << N); ++msk){
            if (!(msk & (1 << i))) cnt[msk] += cnt[msk + (1 << i)];
        }
    }
    ll ans = 0;
    for (int i = 1; i < (1 << N); ++i){
        ans = (ans + fpow(-1, __builtin_popcount(i) + 1) * fpow(cnt[i], K) % mod + mod) % mod;
    }
    cout << ans << '\n';
}
