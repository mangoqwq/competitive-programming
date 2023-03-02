#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    struct Edge{
        int a, b, l, c;
        bool operator<(const Edge &other) const{
            return tie(l, c) < tie(other.l, other.c);
        }
    };
    vector<Edge> edges;

    for (int i = 0; i < M; ++i){
        int a, b, l, c; cin >> a >> b >> l >> c;
        a--, b--;
        edges.push_back({a, b, l, c});
    }
    sort(edges.begin(), edges.end());

    struct AdjE{
        int to, l, c;
    };
    vector<vector<AdjE>> adj(N);

    auto dijkstra = [&](int src, int dest) -> ll {
        vector<ll> dist(N, 1e18);
        using pii = pair<ll, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()){
            auto [d, v] = pq.top(); pq.pop();
            if (d != dist[v]) continue;
            for (auto [to, l, c] : adj[v]){
                if (dist[v] + l < dist[to]){
                    dist[to] = dist[v] + l;
                    pq.push({dist[to], to});
                }
            }
        }
        return dist[dest];
    };

    ll ans = 0;
    for (auto [a, b, l, c] : edges){
        ll d1 = dijkstra(a, b);
        adj[a].push_back({b, l, c});
        adj[b].push_back({a, l, c});
        ll d2 = dijkstra(a, b);
        if (d2 < d1){
            ans += c;
        }
        else{
            adj[a].pop_back();
            adj[b].pop_back();
        }
    }
    cout << ans << '\n';
}
