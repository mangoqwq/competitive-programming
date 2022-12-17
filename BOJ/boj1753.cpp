#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int src; cin >> src;
    struct Edge{ int to, w; };
    vector<vector<Edge>> adj(N+1);
    for (int i = 0; i < M; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> dist(N+1, 1e9);
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if (d > dist[v]) continue;
        for (auto [to, w] : adj[v]){
            if (d + w < dist[to]){
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        }
    }
    for (int i = 1; i <= N; ++i){
        if (dist[i] == 1e9) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}
