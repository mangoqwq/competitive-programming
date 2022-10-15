#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
#endif
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase){
        cout << "Case #" << testcase << ": ";
        int n; cin >> n;
        string s; cin >> s;
        int last = -1;
        ll cur = 0, ans = 0;
        for (int i = 0; i < n; ++i){
            if (s[i] != 'F' && last == -1) last = i;
            if (s[i] != 'F' && s[i] != s[last]){
                cur = (cur + last + 1) % mod;
            }
            if (s[i] != 'F') last = i;
            ans = (ans + cur) % mod;
        }
        cout << ans << '\n';
    }
}
