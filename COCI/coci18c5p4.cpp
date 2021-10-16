#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e4 + 1, MM = 6;
const int seed = 131;

unordered_map<ll, int> cnt[(1 << MM)][(1 << MM)];
ll get_hash(string s, int mask){
    ll ret = 0;
    for (int i = 0; i < s.size(); ++i){
        if (!(1 & (mask >> i))) continue;
        ret = ret * seed + s[i];
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    ll ans = 0;
    for (int _ = 1; _ <= n; ++_){
        string s; cin >> s;
        int cur = 0;
        for (int i = 0; i < m; ++i){
            if (s[i] != '?') cur += (1 << i);
        }
        for (int i = 0; i < (1 << m); ++i){
            ll j = i & cur;
            ll hsh = get_hash(s, j);
            if (cnt[i][j].count(hsh)){
                ans += cnt[i][j][hsh];
            }
        }
        for (int i = cur; ; i = (i - 1) & cur){
            cnt[cur][i][get_hash(s, i)]++;
            if (i == 0) break;
        }
    }
    cout << ans << '\n';
}
