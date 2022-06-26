#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> a(M), b(M);
    for (int i = 0; i < M; ++i){
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < M; ++i){
        cin >> b[i]; b[i]--;
    }

    struct Edge{ int to, id, dir; };
    vector<vector<Edge>> adj(N);
    for (int i = 0; i < M; ++i){
        adj[a[i]].push_back({b[i], i, 0});
        adj[b[i]].push_back({a[i], i, 1});
    }

    vector<bool> vis(N), used(M);
    vector<int> ans(M);
    function<void(int)> dfs = [&](int v){
        vis[v] = 1;
        for (auto [to, id, dir] : adj[v]){
            if (used[id]) continue;
            ans[id] = dir;
            used[id] = 1;
            if (!vis[to]) dfs(to);
        }
    };
    for (int i = 0; i < N; ++i){
        if (!vis[i]) dfs(i);
    }
    for (int i = 0; i < M; ++i){
        cout << ans[i];
    }
    cout << '\n';
}
