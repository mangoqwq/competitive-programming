#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; int K; cin >> N >> K;
    vector<ll> a(K);
    for (auto &x : a) cin >> x;
    ll ans = 0;
    for (int i = 0; i < (1 << K); ++i){
        ll lcm = 1;
        for (int j = 0; j < K; ++j){
            if (!((1 << j) & i)) continue;
            if (a[j] > N / lcm) lcm = N + 1;
            else lcm *= a[j];
        }
        ans += N / lcm * (__builtin_popcount(i) % 2 == 0 ? 1 : -1);
    }
    cout << N - ans << '\n';
}
