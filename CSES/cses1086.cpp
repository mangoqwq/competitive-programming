#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Item{ ll dp, c0, c1; } dp[19][2][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    function<Item(const string&, int, bool, bool)> go = [&](const string &s, int idx, bool high, bool zero) -> Item{
        if (idx == s.size()) return {!zero, 0, 0};
        Item &cur = dp[idx][high][zero];
        if (cur.dp != -1) return cur;
        cur = {0, 0, 0};
        int l = 0, r = (high ? s[idx] - '0' : 9);
        for (int i = l; i <= r; ++i){
            bool nhigh = (i == r) & high;
            bool nzero = (i == 0) & zero;

            Item nxt = go(s, idx + 1, nhigh, nzero);
            cur.dp += nxt.dp;
            cur.c0 += nxt.c0;
            cur.c1 += nxt.c1;
            if (!zero && i == 0) cur.c0 += nxt.dp;
            if (i == 1) cur.c1 += nxt.dp;
        }
        return cur;
    };
    ll lo = 1, hi = 1e18;
    while (lo < hi){
        ll mid = (lo + hi + 1) >> 1;
        memset(dp, -1, sizeof dp);
        Item nya = go(to_string(mid), 0, 1, 1);
        if (max(nya.c0, nya.c1) <= N) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
}
