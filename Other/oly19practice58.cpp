#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

ll N;
bool check(ll av){
    ll cnt = N / av;
    ll s = (av + 1) / 2 - (cnt / 2);
    return s > 0 && (2 * s + cnt - 1) * cnt == N;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N; N *= 2;
    ll ans = 0;
    for (ll i = 1; i * i <= N; ++i){
        if (N % i) continue;
        ans += check(i);
        if (i != N / i) ans += check(N / i);
    }
    cout << ans << '\n';
}
