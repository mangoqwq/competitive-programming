#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 20;
ll p[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll tot = 0;
    for (int i = 0; i < N; ++i){
        cin >> p[i];
        tot += p[i];
    }
    ll ans = tot;
    for (int i = 0; i < (1 << N); ++i){
        ll x = 0;
        for (int j = 0; j < N; ++j){
            x += (1 & (i >> j)) * p[j];
        }
        ans = min(ans, abs(2 * x - tot));
    }
    cout << ans << '\n';
}
