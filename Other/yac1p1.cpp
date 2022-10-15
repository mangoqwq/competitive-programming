#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N, K; cin >> N >> K;
    vector<ll> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll& x = a[N], &y = b[N];
    if (y < x) swap(x, y);
    if (x < y){
        ll diff = min(y - x, K);
        x += diff, K -= diff;
    }
    x += (K / 2);
    y += (K + 1) / 2;
    ll tot = 0;
    for (int i = 1; i <= N; ++i) tot = (tot + 1LL * a[i] * b[i]) % mod;
    cout << tot << '\n';
}
