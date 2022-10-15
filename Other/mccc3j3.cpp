#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int S, T; cin >> S >> T;
    string s, t; cin >> s >> t;
    map<char, int> cnt;
    for (char c : s) cnt[c]++;
    int mn = inf, mx = 0;
    ll ans = 0;
    for (char c : t){
        mn = min(mn, cnt[c]);
        ans += cnt[c];
    }
    for (auto [a, b] : cnt) mx = max(mx, b);
    ans -= mn; ans += mx;
    cout << ans << '\n';
}
