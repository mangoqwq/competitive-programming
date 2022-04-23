#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;
struct State{ ll ans, cnt; } dp[51][2];
ll N;

State solve(int i = 50, bool upper = 1){
    if (i == -1) return {0, 1};
    State &cur = dp[i][upper];
    if (cur.ans != -1) return cur;
    cur = {0, 0};
    int r = (upper ? 1 & (N >> i) : 1);
    for (int b = 0; b <= r; ++b){
        State nxt = solve(i - 1, upper & (b == r));
        cur.cnt += nxt.cnt;
        cur.ans += nxt.ans;
        if (b == 1) cur.ans += nxt.cnt;
    }
    return cur;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    ms(dp, -1);
    cout << solve().ans << '\n';
}
