#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (ll k = 1; k <= N; ++k){
        ll ans = (k * k) * (k * k);
        ans -= (k * k);
        ans -= 2 * ((k - 1) * (k - 2) * 2 * 2);
        cout << ans / 2 << '\n';
    }
}
