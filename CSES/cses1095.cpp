#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

ll fpow(ll b, ll e, ll m){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % m;
        b = b * b % m; e >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll a, b, c; cin >> a >> b >> c;
        cout << fpow(a, fpow(b, c, mod - 1), mod) << '\n';
    }
}
