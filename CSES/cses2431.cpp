#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int Q; cin >> Q;
    while (Q--){
        ll k; cin >> k;
        ll r = 9;
        for (int dig = 1; ; ++dig){
            if (k <= r * dig){
                cout << to_string((k + dig - 1) / dig + r / 9 - 1)[(k - 1) % dig] << '\n';
                break;
            }
            k -= r * dig;
            r *= 10;
        }
    }
}
