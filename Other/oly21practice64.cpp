#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 2;
const ll inv = (mod + 1) >> 1;

int heights[MN], widths[MN];
struct Rect{ ll h, w; };
stack<Rect> s;
ll count(ll h, ll w){
    return (h * (h + 1) % mod * w % mod * (w + 1) % mod) * inv % mod * inv % mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll ans = 0;
    s.push({0, 0});
    for (int i = 1; i <= N; ++i) cin >> heights[i];
    for (int i = 1; i <= N; ++i) cin >> widths[i];
    for (int i = 1; i <= N + 1; ++i){
        ll h = heights[i], w = widths[i];
        while (s.top().h && s.top().h >= h){
            auto [lh, lw] = s.top(); s.pop();
            ll b;
            if (s.top().h < h){
                b = h;
                w = (w + lw) % mod;
            }
            else{
                b = s.top().h;
                s.top().w = (s.top().w + lw) % mod;
            }
            ans = (ans + count(lh, lw) - count(b, lw) + mod) % mod;
        }
        s.push({h, w});
    }
    cout << ans << '\n';
}
