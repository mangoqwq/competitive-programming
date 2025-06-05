#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, M; cin >> N >> M;
  vector<int> cost(M);
  for (int i = 0; i < M; ++i) {
    cin >> cost[i];
  }
  struct Edge { int to, w; };
  vector<vector<Edge>> adj(N + M);
  for (int i = 0; i < M; ++i) {
    int k; cin >> k;
    while (k--) {
      int v; cin >> v; v--;
      adj[v].emplace_back(N + i, cost[i]);
      adj[N + i].emplace_back(v, 0);
    }
  }
  vector<ll> dist(N + M, 1e18);
  dist[0] = 0;
  struct Item {
    int v; ll dist;
    bool operator<(const Item &other) const { return dist > other.dist; }
  };
  priority_queue<Item> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [v, d] = pq.top(); pq.pop();
    if (d > dist[v]) continue;
    for (auto [to, w] : adj[v]) {
      if (dist[to] > d + w) {
        dist[to] = d + w;
        pq.emplace(to, d + w);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << dist[i] << (i == N - 1 ? '\n' : ' ');
  }
}
