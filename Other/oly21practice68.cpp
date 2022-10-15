#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

ll x[MN], p[MN], c[MN], xp[MN], dp[MN], q[MN], pl, pr;
double sect(int i, int j){
    if (p[i] == p[j]) return (dp[i] - xp[i] < dp[j] - xp[j]) ? -inf : inf;
    return (.0 + dp[j] + xp[j] - dp[i] - xp[i]) / (-p[i] + p[j]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> p[i] >> c[i];
    for (int i = 1; i <= n; ++i){
        xp[i] = xp[i - 1] + x[i] * p[i];
        p[i] = p[i - 1] + p[i];
    }
    ms(dp, 0x3f); dp[0] = 0;
    q[0] = 0;
    for (int i = 1; i <= n; ++i){
        while (pr > pl && sect(q[pl + 1], q[pl]) <= x[i]) pl++;
        int j = q[pl];
        dp[i] = (-p[j] * x[i] + dp[j] + xp[j]) + p[i] * x[i] - xp[i] + c[i];
        while (pr > pl && sect(i, q[pr]) <= sect(q[pr], q[pr - 1])) pr--;
        q[++pr] = i;
    }
    cout << dp[n] << '\n';
}
