#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    const int L = 1e6;
    int K = 0;
    vector<int> vis(N);
    auto dfs = [&](auto self, int v) -> void{
        if (K >= L) return;
        K++;
        vis[v] = 1;
        for (int to : adj[v]){
            if (vis[to]) continue;
            self(self, to);
        }
        vis[v] = 0;
    };
    dfs(dfs, 0);
    cout << K << '\n';
}
