#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

void solve(){
    string s; cin >> s;
    string ans = "";
    char lst = ' '; bool flag = 0;
    for (int i = s.size() - 1; i >= 0; --i){
        if (s[i] != lst){
            if (s[i] < lst) flag = 1;
            else flag = 0;
        }
        ans += s[i];
        if (flag) ans += s[i];
        lst = s[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
