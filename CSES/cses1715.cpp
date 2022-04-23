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
    vector<ll> fact(1e6 + 1), inv(1e6 + 1);
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= 1e6; ++i){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = fpow(fact[i], mod - 2);
    }
    string s; cin >> s;
    int N = s.size();
    ll ans = fact[N];
    map<int, int> mp;
    for (char c : s) mp[c]++;
    for (auto [a, b] : mp) ans = ans * inv[b] % mod;
    cout << ans << '\n';
}
