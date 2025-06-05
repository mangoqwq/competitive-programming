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
  vector<int> dep;
  vector<int> in, out;
  LCA (vector<vector<pair<int, int>>> adj, int rt) 
    : N(adj.size()), L(__lg(N)+1), up(N, vector<int>(L)), mx(N, vector<int>(L)), dep(N), in(N), out(N) {
    int T = 0;
    auto dfs = [&](auto self, int v, int p, ll ld) -> void {
      in[v] = ++T;
      up[v][0] = p;
      mx[v][0] = ld;
      for (int i = 1; i < L; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        mx[v][i] = max(mx[v][i-1], mx[up[v][i-1]][i-1]);
      }
      for (auto [to, w] : adj[v]) {
        if (to == p) continue;
        dep[to] = dep[v] + 1;
        self(self, to, v, w);
      }
      out[v] = T;
    };
    dfs(dfs, rt, rt, 0);
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
  int mx_qry(int a, int b) {
    int p = lca(a, b);
    int upa = dep[a] - dep[p], upb = dep[b] - dep[p];
    int ret = 0;
    for (int i = L-1; i >= 0; --i) {
      if (upa >= (1 << i)) {
        ret = max(ret, mx[a][i]);
        a = up[a][i];
        upa -= (1 << i);
      }
    }
    for (int i = L-1; i >= 0; --i) {
      if (upb >= (1 << i)) {
        ret = max(ret, mx[b][i]);
        b = up[b][i];
        upb -= (1 << i);
      }
    }
    return ret;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, M; cin >> N >> M;
  struct Edge { int a, b, w; };
  vector<Edge> edges(M);
  for (auto &[a, b, w] : edges) {
    cin >> a >> b >> w;
    a--, b--;
  }
  vector<int> ord(M);
  iota(ord.begin(), ord.end(), 0);
  ranges::sort(ord, [&](int i, int j) {
    return edges[i].w < edges[j].w;
  });

  DisjointSet dsu(N);
  vector<vector<pair<int, int>>> adj(N);
  for (int i : ord) {
    auto [a, b, w] = edges[i];
    debug(a+1, b+1, w);
    if (dsu.unite(a, b)) {
      adj[a].emplace_back(b, w);
      adj[b].emplace_back(a, w);
      // debug(a+1, b+1, w);
    }
  }

  LCA t(adj, 0);
  for (auto &[a, b, w] : edges) {
    cout << (t.mx_qry(a, b) >= w ? "YES" : "NO") << '\n';
  }
}
