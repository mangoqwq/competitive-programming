#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int N, Q;
ll a[MN], qs[MN];
map<ll, int> mp;
vector<pair<ll, int>> primes;
map<ll, int> dp;

void build(int i, ll v){
    if (i == primes.size()) dp[v] = 0;
    else{
        build(i + 1, v);
        for (int j = 1; j <= primes[i].second; ++j){
            v *= primes[i].first;
            build(i + 1, v);
        }
    }
}

void factor(ll x){
    for (int i = 2; i <= 1e6; ++i){
        while (x % i == 0){
            x /= i;
            mp[i]++;
        }
    }
    vector<ll> cand;
    for (int i = 1; i <= N; ++i) cand.push_back(a[i]);
    for (int i = 1; i <= Q; ++i) cand.push_back(qs[i]);
    for (ll v : cand){
        ll g = gcd(v, x);
        if (g != 1 && g != x){
            mp[g]++;
            mp[x / g]++;
            x = 1;
            break;
        }
    }
    if (x != 1) mp[x]++;
    for (auto [p, cnt] : mp) primes.push_back({p, cnt});
    build(0, 1);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i]; a[i] += a[i - 1];
    }
    for (int i = 1; i <= N; ++i){
        a[i] = gcd(a[i], a[N]);
    }
    cin >> Q;
    for (int i = 1; i <= Q; ++i) cin >> qs[i];
    for (int i = 1; i <= N; ++i) dp[a[i]]++;
    factor(a[N]);
    for (int i = 1; i <= N; ++i){
        dp[a[i]]++;
    }
    vector<ll> lst;
    for (auto [f, c] : dp) lst.push_back(f);
    reverse(lst.begin(), lst.end());
    for (auto [p, cnt] : primes){
        for (ll v : lst){
            if (dp.count(v * p)) dp[v] += dp[v * p];
        }
    }
    for (int i = 1; i <= Q; ++i){
        if (a[N] % qs[i]) cout << -1 << '\n';
        else cout << N + a[N] / qs[i] - 2 * dp[qs[i]] << '\n';
    }
}
