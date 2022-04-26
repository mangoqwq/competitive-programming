#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<pair<int, int>> edges;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dep(N + 1), up(N + 1);
    bool bad = 0; int cnt = 0;
    function<void(int, int)> dfs = [&](int v, int p){
        cnt++;
        up[v] = dep[v];
        for (int to : adj[v]){
            if (to == p) continue;
            if (dep[to]){
                if (dep[to] > dep[v]) continue;
                edges.push_back({v, to});
                up[v] = min(up[v], dep[to]);
            }
            else{
                edges.push_back({v, to});
                dep[to] = dep[v] + 1;
                dfs(to, v);
                up[v] = min(up[v], up[to]);
            }
        }
        if (up[v] == dep[v] && v != p) bad = 1;
    };
    dep[1] = 1; dfs(1, 1);
    if (bad || cnt != N) cout << "IMPOSSIBLE" << '\n';
    else{
        for (auto [a, b] : edges) cout << a << " " << b << '\n';
    }

}
