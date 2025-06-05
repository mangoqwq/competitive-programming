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
  struct Edge { int to; ll s; };
  vector<vector<Edge>> adj(N + 1);
  for (int i = 0; i < M; ++i) {
    int a, b, s; cin >> a >> b >> s; a--;
    adj[a].push_back({b, s});  // psa[b] - psa[a] = s
    adj[b].push_back({a, -s}); // psa[a] - psa[b] = -s
  }

  vector<int> vis(N + 1), psa(N + 1);
  bool ok = 1;
  auto dfs = [&](auto self, int v) -> void {
    vis[v] = 1;
    for (auto [to, s] : adj[v]) {
      if (vis[to]) {
        ok &= psa[to] == s + psa[v];
        continue;
      }
      psa[to] = s + psa[v];
      self(self, to);
    }
  };
  for (int i = 0; i < N; ++i) {
    if (!vis[i]) {
      dfs(dfs, i);
    }
  }
  if (!ok) {
    cout << "NO" << '\n';
  }
  else {
    cout << "YES" << '\n';
    for (int i = 0; i < N; ++i) {
      cout << psa[i + 1] - psa[i] << (i == N - 1 ? '\n' : ' ');
    }
  }
}
