#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 20;
string a, b;
ll dp[MN][11][2][2][2];

ll solve(int i, int last, bool zero, bool low, bool high){
    if (i == a.size()) return 1;
    ll &cur = dp[i][last][zero][low][high];
    if (cur != -1) return cur;
    cur = 0;
    int lo = (low ? a[i] - '0' : 0);
    int hi = (high ? b[i] - '0' : 9);
    for (int c = lo; c <= hi; ++c){
        if (!zero && c == last) continue;
        cur += solve(i + 1, c, zero & (c == 0), low & (c == lo), high & (c == hi));
    }
    return cur;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(dp, -1);
    cin >> a >> b;
    while (a.size() < b.size()) a = "0" + a;
    cout << solve(0, 10, 1, 1, 1) << '\n';
}
