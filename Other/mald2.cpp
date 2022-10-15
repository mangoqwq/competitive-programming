#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll g, t; cin >> g >> t;
        ll x = (100 * g + t - 1) / t;
        if (x > 100) cout << "sus" << '\n';
        else if (x == 100) cout << "average" << '\n';
        else if (x >= 98) cout << "below average" << '\n';
        else if (x >= 95) cout << "can't eat dinner" << '\n';
        else if (x >= 90) cout << "don't come home" << '\n';
        else cout << "find a new home" << '\n';
    }
}
