#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans = inf;
    for (int i = 0; i <= 1000; ++i){
        int j = (n - i * 5) / 3;
        if (i * 5 + j * 3 == n && j >= 0){
            ans = min(ans, i + j);
        }
    }
    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}
