#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1, MQ = 5e5 + 1;

int m[MN], b[MN], idx[MQ], q[MN], ask[MQ], ans[MQ];
double sect(int l, int r){
    if (m[l] == m[r]) return b[l] < b[r] ? inf : -inf;
    return ((double)b[r] - b[l]) / (m[l] - m[r]);
}
pll eval(ll i, ll x){ return {m[i] * x + b[i], inf - i}; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i) cin >> b[i] >> m[i];
    iota(idx + 1, idx + 1 + N, 1);
    sort(idx + 1, idx + 1 + N, [](int l, int r){ return m[l] < m[r]; });
    int pl = 1, pr = 0;
    for (int j = 1; j <= N; ++j){
        int i = idx[j];
        while (pl < pr && sect(i, q[pr]) < sect(q[pr], q[pr - 1])) pr--;
        q[++pr] = i;
    }
    for (int i = 1; i <= Q; ++i) cin >> ask[i];
    iota(idx + 1, idx + 1 + Q, 1);
    sort(idx + 1, idx + 1 + Q, [](int l, int r){ return ask[l] < ask[r]; });
    for (int i = 1; i <= Q; ++i){
        ll x = ask[idx[i]];
        while (pl < pr && eval(q[pl], x) < eval(q[pl + 1], x)) pl++;
        ans[idx[i]] = q[pl];
    }
    for (int i = 1; i <= Q; ++i) cout << ans[i] - 1 << '\n';
}
