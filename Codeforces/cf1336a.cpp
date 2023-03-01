#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N-1; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    vector<int> dist(N), sz(N);
    auto dfs = [&](auto self, int v, int p, int d) -> int {
        sz[v] = 1;
        dist[v] = d;
        for (int to : adj[v]){
            if (to == p) continue;
            sz[v] += self(self, to, v, d+1);
        }
        return sz[v];
    };
    dfs(dfs, 0, 0, 0);

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return sz[i] - dist[i] > sz[j] - dist[j];
    });

    ll ans = 0;
    for (int i = 0; i < N-K; ++i){
        ans += sz[ord[i]] - 1 - dist[ord[i]];
    }
    cout << ans << '\n';
}
