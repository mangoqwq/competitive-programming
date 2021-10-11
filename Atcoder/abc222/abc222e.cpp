#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 998244353, inf = 0x3f3f3f3f;
const int MN = 1001, MM = 101, MK = 2e5 + 1;

struct Edge{ int to, id; };
vector<Edge> adj[MN];
int val[MN], a[MM];
vector<int> path;
ll dp[MK];

void dfs(int v, int p, int tar){
    if (v == tar){
        for (int x : path) val[x]++;
    }
    for (auto [to, id] : adj[v]){
        if (to == p) continue;
        path.push_back(id);
        dfs(to, v, tar);
        path.pop_back();
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    for (int i = 1; i < m; ++i){
        dfs(a[i], a[i], a[i + 1]);
    }
    dp[0] = 1;
    int tar = accumulate(val + 1, val + n, 0LL) - k;
    for (int i = 1; i < n; ++i){
        val[i] *= 2;
        for (int j = tar; j >= val[i]; --j){
            dp[j] = (dp[j] + dp[j - val[i]]) % mod;
        }
    }
    if (tar < 0) cout << 0 << '\n';
    else cout << dp[tar] << '\n';
}
