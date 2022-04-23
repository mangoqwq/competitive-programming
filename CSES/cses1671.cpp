#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

struct Edge{ int to, w; };
vector<Edge> adj[MN];
ll dist[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    ms(dist, 0x3f); dist[1] = 0;
    using pli = pair<ll, int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    // queue<pair<ll, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;
        for (auto [to, w] : adj[v]){
            if (d + w < dist[to]){
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        } 
    }
    for (int i = 1; i <= N; ++i) cout << dist[i] << " ";
}
