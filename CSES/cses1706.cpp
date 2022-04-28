#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int MN = 1e5 + 1;
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<bool> vis(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<int(int)> dfs = [&](int v){
        vis[v] = 1;
        int sz = 1;
        for (int to : adj[v]){
            if (vis[to]) continue;
            sz += dfs(to);
        }
        return sz;
    };
    bitset<MN> dp; dp[0] = 1;
    for (int i = 1; i <= N; ++i){
        if (!vis[i]){
            dp |= (dp << dfs(i));
        }
    }
    for (int i = 1; i <= N; ++i) cout << dp[i];
    cout << '\n';
}
