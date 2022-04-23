#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    function<ll(ll, ll)> fpow = [&](ll b, ll e){
        ll ret = 1;
        while (e){
            if (1 & e) ret = ret * b % mod;
            b = b * b % mod; e >>= 1;
        }
        return ret;
    };
    vector<ll> fact(2e6 + 1), inv(2e6 + 1);
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= 1e6; ++i){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = fpow(fact[i], mod - 2);
    }
    function<ll(ll, ll)> choose = [&](ll a, ll b){
        return fact[a] * inv[b] % mod * inv[a - b] % mod;
    };
    int N; cin >> N;
    if (N % 2 == 1) cout << 0 << '\n';
    else{
        N /= 2;
        cout << (choose(2 * N, N) - choose(2 * N, N + 1) + mod) % mod << '\n';
    }
}
