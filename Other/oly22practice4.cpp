#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ull a; cin >> a;
    int k; cin >> k;
    ull ans = ULLONG_MAX;
    if (k == 0){
        for (char c = '0'; c <= '9'; ++c){
            string s = "";
            for (int cnt = 1; cnt <= 18; ++cnt){
                s += c;
                if (stoull(s) >= a) ans = min(ans, stoull(s));
            }
        }
    }
    if (k == 1){
        for (char c = '0'; c <= '9'; ++c){
            for (char d = '0'; d <= '9'; ++d){
                for (int cnt = 1; cnt <= 18; ++cnt){
                    string s = "";
                    for (int i = 1; i <= cnt; ++i) s += c;
                    for (int i = 0; i < cnt; ++i){
                        s[i] = d;
                        if (stoull(s) >= a) ans = min(ans, stoull(s));
                        s[i] = c;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
