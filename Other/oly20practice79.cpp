#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 51;
ll basis[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        ll a; cin >> a;
        for (int j = 50; j >= 0; --j){
            if (1 & (a >> j)){
                if (basis[j]) a ^= basis[j];
                else{
                    basis[j] = a;
                    break;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 50; i >= 0; --i){
        ans = max(ans, ans ^ basis[i]);
    }
    cout << ans << '\n';
}
