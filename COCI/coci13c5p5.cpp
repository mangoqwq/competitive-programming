#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

map<pair<int, int>, ll> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    for (int i = 1; i <= N; ++i){
        int a, b, c; cin >> a >> b >> c;
        int g = gcd(a, b);
        a /= g, b /= g;
        if (a < 0) a *= -1, b *= -1;
        cnt[{a, b}]++;
    }
    ll ans = 0;
    ans += N * (N - 1) * (N - 2) / 6;
    for (auto [a, c] : cnt){
        ans -= c * (c - 1) / 2 * (N - 2);
    }
    for (auto [a, c] : cnt){
        ans += 2 * c * (c - 1) * (c - 2) / 6;
    }
    cout << ans % mod << '\n';
}
