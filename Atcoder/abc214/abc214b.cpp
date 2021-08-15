#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int S, T; cin >> S >> T;
    int ans = 0;
    for (int i = 0; i <= S; ++i){
        for (int j = 0; j <= S; ++j){
            for (int k = 0; k <= S; ++k){
                if (i * j * k <= T && i + j + k <= S) ans++;
            }
        }
    }
    cout << ans << '\n';
}
