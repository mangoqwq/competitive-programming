#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

ll dp[13][121][121][2][2];
ll solve(int i, int prod, int sum, bool upper, bool zero, const string &s){
    if (i == s.size()){
        if (prod == 1 && sum == 0) return 1;
        else return 0;
    }
    ll &cur = dp[i][prod][sum][upper][zero];
    if (cur != -1) return cur;
    cur = 0;
    int up = (upper ? s[i] - '0' : 9);
    for (int c = 0; c <= up; ++c){
        if (c > sum) continue;
        int nprod = prod / gcd(c, prod);
        if (zero & (c == 0)) nprod = prod; 
        cur += solve(i + 1, nprod, sum - c, upper & (c == up), zero & (c == 0), s);
    }
    return cur;
}

void solve(){
    ll vA, vB; cin >> vA >> vB;
    vA--;
    string A = to_string(vA), B = to_string(vB);
    ll ans = 0;
    for (int i = 1; i <= 120; ++i){
        ms(dp, -1);
        ll b = solve(0, i, i, 1, 1, B);
        ms(dp, -1);
        ll a;
        if (vA == 0) a = 0;
        else a = solve(0, i, i, 1, 1, A);
        ans += b - a;
    }
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
