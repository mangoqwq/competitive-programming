#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    set<pair<int, int>> bridges;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int rts = 0;
    vector<int> vis(N + 1), up(N + 1);
    function<int(int, int)> dfs = [&](int v, int p) -> int{
        vis[v] = 1;
        for (int to : adj[v]){
            if (to == p) continue;
            if (vis[to] == 1) up[v]++;
            else if (vis[to] == 2) up[v]--;
            else{
                dfs(to, v);
                up[v] += up[to];
            }
        }
        vis[v] = 2;
        if (!up[v] && v != p){
            bridges.insert({v, p});
        }
        return up[v];
    };
    for (int i = 1; i <= N; ++i){
        if (!vis[i]){
            rts++;
            dfs(i, i);
        }
    }
    cout << bridges.size() << '\n';
    for (auto [a, b] : bridges) cout << a << " " << b << '\n';
}
