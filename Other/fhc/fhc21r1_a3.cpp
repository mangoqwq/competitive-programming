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
        int k; cin >> k;
        ll sz = 0, cur = 0, pre = 0, ans = 0, fo = inf, fx = inf, last = 0, inv = 0; char lastc = '#';
        int order = -1;
        while (k--){
            char c; cin >> c;
            if (c == '.'){
                ans = (ans + cur * sz + pre * sz + ans) % mod;
                cur = (cur + inv * sz + cur) % mod;
                pre = (pre + inv * sz + pre) % mod;
                inv = inv * 2 % mod;
                if (lastc == 'O' && order == 1){
                    ans = (ans + last * (sz - fx + 1 + mod)) % mod;
                    cur = (cur + last) % mod;
                    pre = (pre + (sz - fx + 1 + mod)) % mod;
                    inv = (inv + 1) % mod;
                }   
                if (lastc == 'X' && order == 0){
                    ans = (ans + last * (sz - fo + 1 + mod)) % mod;
                    cur = (cur + last) % mod;
                    pre = (pre + (sz - fo + 1 + mod)) % mod;
                    inv = (inv + 1) % mod;
                }
                if (lastc != '#') last = (last + sz) % mod;
                sz = sz * 2 % mod;
            }
            else{
                sz = (sz + 1) % mod;
                if (c == 'O'){
                    if (order == -1) order = 0;
                    if (fo == inf) fo = sz;
                    if (c != lastc && lastc != '#'){
                        inv = (inv + 1) % mod;
                        cur = (cur + last) % mod;
                    }
                    last = sz; lastc = c;
                }
                if (c == 'X'){
                    if (order == -1) order = 1;
                    if (fx == inf) fx = sz;
                    if (c != lastc && lastc != '#'){
                        inv = (inv + 1) % mod;
                        cur = (cur + last) % mod;
                    }
                    last = sz; lastc = c;
                }
                pre = (pre + inv) % mod;
                ans = (ans + cur) % mod;
            }
            assert(min({sz, cur, pre, ans, last, inv}) >= 0);
            assert(max({sz, cur, pre, ans, last, inv}) < mod);
        }
        cout << ans << '\n';
    }
}
