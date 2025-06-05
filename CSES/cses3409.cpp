#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct DisjointSet {
  vector<int> p, sz;
  DisjointSet(int N) {
    p.resize(N);
    iota(p.begin(), p.end(), 0);
    sz.resize(N, 1);
  }
  int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
  bool unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return 0;
    if (sz[b] > sz[a]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return 1;
  }
};

struct LCA {
  int N, L;
  vector<vector<int>> up;
  vector<vector<int>> mx;
  vector<int> in, out;
  const int e = 0;
  LCA (vector<vector<pair<int, int>>> adj, int rt) 
    : N(adj.size()), L(__lg(N)+1), up(N, vector<int>(L)), mx(N, vector<int>(L)), in(N), out(N) {
    int T = 0;
    auto dfs = [&](auto self, int v, int p, ll lw) -> void {
      in[v] = ++T; up[v][0] = p;
      mx[v][0] = lw;
      for (int i = 1; i < L; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        mx[v][i] = max(mx[v][i-1], mx[up[v][i-1]][i-1]);
      }
      for (auto [to, w] : adj[v]) {
        if (to == p) continue;
        self(self, to, v, w);
      }
      out[v] = T;
    };
    dfs(dfs, rt, rt, e);
  }
  bool is_anc(int a, int b) {
    return in[a] <= in[b] && out[a] >= out[b];
  }
  int lca(int a, int b) {
    if (is_anc(a, b)) return a;
    if (is_anc(b, a)) return b;
    for (int i = L-1; i >= 0; --i) {
      if (!is_anc(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
  }
  int qry(int a, int b) {
    int g = lca(a, b);
    int ret = e;
    for (int i = L-1; i >= 0; --i) {
      if (!is_anc(up[a][i], g)) {
        ret = max(ret, mx[a][i]);
        a = up[a][i];
      }
      if (!is_anc(up[b][i], g)) {
        ret = max(ret, mx[b][i]);
        b = up[b][i];
      }
    }
    if (a != g) ret = max(ret, mx[a][0]);
    if (b != g) ret = max(ret, mx[b][0]);
    return ret;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, M; cin >> N >> M;
  struct Edge { int u, v, w; };
  vector<Edge> edges(M);
  for (auto &[u, v, w] : edges) {
    cin >> u >> v >> w; u--, v--;
  }
  
  vector<int> ord(M);
  iota(ord.begin(), ord.end(), 0);
  ranges::sort(ord, {}, [&](int i) { return edges[i]. w; });

  ll mst = 0;
  DisjointSet dsu(N);
  vector<vector<pair<int, int>>> adj(N);
  for (auto i : ord) {
    auto [u, v, w] = edges[i];
    if (dsu.unite(u, v)) {
      mst += w;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }
  }

  LCA t(adj, 0);

  for (auto &[u, v, w] : edges) {
    cout << mst - t.qry(u, v) + w << '\n';
  }
}
