#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

multiset<ll> s[MN];
vector<ll> dist[MN];
struct Edge{ int to, w; };
vector<Edge> adj[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= M; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    struct Item{
        ll d, v;
        bool operator<(const Item &other) const{
            return d > other.d;
        }
    };
    priority_queue<Item> pq;
    s[1].insert(0);
    pq.push({0, 1});
    while (!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if (!s[v].count(d)) continue;
        s[v].erase(s[v].find(d));
        dist[v].push_back(d);
        for (auto [to, w] : adj[v]){
            ll nd = d + w;
            ll cnt = dist[to].size() + s[to].size();
            if (dist[to].size() == K) continue;
            if (cnt < K || nd < *--s[to].end()){
                if (!(cnt < K)) s[to].erase(--s[to].end());
                s[to].insert(nd);
                pq.push({nd, to});
            }
        }
    }
    for (ll x : dist[N]) cout << x << " ";
    cout << '\n';
}
