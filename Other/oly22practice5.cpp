#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
const ll infll = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[MN];
int a[MN];
ll dp[MN][2][2];

void dfs(int v, int p){
    vector<ll> v0, v1;
    ll tot0 = 0, tot1 = 0;
    for (int to : adj[v]){
        if (to == p) continue;
        dfs(to, v);
        tot0 += dp[to][0][0];
        v0.push_back(dp[to][0][1] - dp[to][0][0]);
        tot1 += dp[to][1][0];
        v1.push_back(dp[to][1][1] - dp[to][1][0]);
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    dp[v][a[v]][0] = tot0;
    dp[v][a[v] ^ 1][1] = tot1 + 1;
    for (int i = 0; i < v0.size(); ++i){
        int c = (i + 1) % 2;
        tot0 += v0[i];
        tot1 += v1[i];
        dp[v][a[v] ^ c][0] = min(dp[v][a[v] ^ c][0], tot0);
        dp[v][a[v] ^ c ^ 1][1] = min(dp[v][a[v] ^ c ^ 1][1], tot1 + 1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = inf;
    }
    for (int i = 1; i <= N - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i) cin >> a[i];
    dfs(1, 1);
    ll ans = min(dp[1][0][0], dp[1][0][1]);
    if (ans == inf) cout << "impossible" << '\n';
    else cout << ans << '\n';
}
