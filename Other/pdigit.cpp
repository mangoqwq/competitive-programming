#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        ll p10 = 1;
        while (p10 <= n) p10 *= 10;
        if ((k - n) % gcd(p10, k) == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
