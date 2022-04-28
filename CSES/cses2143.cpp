#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int MX = 5e4;
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> adj(N), rev(N);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<int> vis(N), ord;
    function<void(int)> dfs0 = [&](int v){
        vis[v] = 1;
        for (int to : adj[v]) if (!vis[to]) dfs0(to);
        ord.push_back(v);
    };
    for (int i = 0; i < N; ++i) if (!vis[i]) dfs0(i);
    reverse(ord.begin(), ord.end());

    vis = vector<int>(N, 0);
    vector<int> root(N);
    function<void(int, int)> dfs1 = [&](int v, int rt){
        vis[v] = 1;
        root[v] = rt;
        for (int to : rev[v]) if (!vis[to]) dfs1(to, rt);
    };
    for (int v : ord){
        if (!vis[v]) dfs1(v, v);
    }
    vector<bitset<MX>> ans(N);
    for (int i = 0; i < N; ++i){
        ans[root[i]][root[i]] = 1;
    }
    reverse(ord.begin(), ord.end());
    for (int v : ord){
        for (int to : adj[v]){
            ans[root[v]] |= ans[root[to]];
        }
    }
    
    while (Q--){
        int a, b; cin >> a >> b; a--, b--;
        a = root[a], b = root[b];
        cout << (ans[a][b] ? "YES" : "NO") << '\n';
    }
}
