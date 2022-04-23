#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 1e9;
    vector<int> dist(N + 1);
    function<void(int, int)> dfs = [&](int v, int p){
        for (int to : adj[v]){
            if (to == p) continue;
            if (dist[to]){
                ans = min(ans, abs(dist[v] - dist[to]) + 1);
            }
            else{
                dist[to] = dist[v] + 1;
                dfs(to, v);
            }
        }
    };
    for (int i = 1; i <= N; ++i){
        dist = vector<int>(N + 1, 0);
        dist[i] = 1;
        dfs(i, i);
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
}
