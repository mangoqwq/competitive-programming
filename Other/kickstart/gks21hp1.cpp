#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

void solve(){
    string s, t; cin >> s >> t;
    int ans = 0;
    for (char c : s){
        int cur = 26;
        for (char d : t){
            cur = min(cur, abs(c - d));
            cur = min(cur, 26 - abs(c - d));
        }
        ans += cur;
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
