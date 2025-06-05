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
  int N, M, K; cin >> N >> M >> K;
  vector<int> shop(N);
  for (int i = 0; i < K; ++i) {
    int x; cin >> x; x--;
    shop[x]++;
  }
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dist(N, 1e9);
  vector<int> src(N);
  queue<int> q;
  for (int i = 0; i < N; ++i) {
    if (shop[i]) {
      q.push(i);
      dist[i] = 0;
      src[i] = i;
    }
  }
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int to : adj[v]) {
      if (dist[to] > dist[v] + 1) {
        dist[to] = dist[v] + 1;
        src[to] = src[v];
        q.push(to);
      }
    }
  }
  vector<int> ans = dist;
  for (int i = 0; i < N; ++i) {
    if (shop[i]) ans[i] = 1e9;
  }
  for (int v = 0; v < N; ++v) {
    for (int u : adj[v]) {
      if (src[u] == src[v]) continue;
      int d = dist[v] + dist[u] + 1;
      ans[src[v]] = min(ans[src[v]], d);
      ans[src[u]] = min(ans[src[u]], d);
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << (ans[i] == 1e9 ? -1 : ans[i]) << (i == N - 1 ? '\n' : ' ');
  }
}
