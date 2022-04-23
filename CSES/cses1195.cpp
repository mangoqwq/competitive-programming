#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

struct Edge{ int to, w; };
vector<Edge> adj[MN];
ll dist[MN][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    ms(dist, 0x3f); dist[1][0] = 1;
    struct Item{
        ll d; int to, c;
        bool operator<(const Item &other) const{
            return d > other.d;
        }
    };
    priority_queue<Item> pq;
    pq.push({0, 1, 0});
    while (!pq.empty()){
        auto [d, v, c] = pq.top(); pq.pop();
        if (d > dist[v][c]) continue;
        for (auto [to, w] : adj[v]){
            if (w + d < dist[to][c]){
                dist[to][c] = w + d;
                pq.push({dist[to][c], to, c});
            }
            if (c == 1) continue;
            if (w / 2 + d < dist[to][c + 1]){
                dist[to][c + 1] = w / 2 + d;
                pq.push({dist[to][c + 1], to, c + 1});
            }
        }
    }
    cout << min(dist[N][0], dist[N][1]) << '\n';
}
