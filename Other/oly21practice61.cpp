#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<ll> v(N);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    ll ans = 0, cur = 0;
    for (int i = 1; i < N; ++i){
        ans += (v[i] - v[i - 1]) * i * (N - i);
    }
    cout << ans << '\n';
}
