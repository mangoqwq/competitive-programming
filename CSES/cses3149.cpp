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
  vector<int> in, out;
  LCA (vector<vector<int>> adj, int rt) 
    : N(adj.size()), L(__lg(N)+1), up(N, vector<int>(L)), in(N), out(N) {
    int T = 0;
    auto dfs = [&](auto self, int v, int p) -> void {
      in[v] = ++T; up[v][0] = p;
      for (int i = 1; i < L; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
      }
      for (int to : adj[v]) {
        if (to == p) continue;
        self(self, to, v);
      }
      out[v] = T;
    };
    dfs(dfs, rt, rt);
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
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, Q; cin >> N >> Q;
  vector<int> coin(N);
  for (int i = 0; i < N; ++i) {
    cin >> coin[i];
  }
  int rt = ranges::find(coin, 1) - coin.begin();
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b; cin >> a >> b; a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> mark(N);
  auto dfs = [&](auto self, int v, int p) -> void {
    mark[v] = coin[v];
    for (int to : adj[v]) {
      if (to == p) continue;
      self(self, to, v);
      mark[v] |= mark[to];
    }
  };
  dfs(dfs, rt, rt);

  vector<int> par(N), pre(N), dep(N);
  auto calc = [&](auto self, int v) -> void {
    for (int to : adj[v]) {
      if (to == par[v]) continue;
      par[to] = v;
      dep[to] = dep[v] + 1;
      pre[to] = pre[v] + mark[to];
      self(self, to);
    }
  };
  pre[rt] = mark[rt];
  calc(calc, rt);
  int base = accumulate(mark.begin(), mark.end(), -1) * 2;


  LCA tree(adj, rt);
  while (Q--) {
    int a, b; cin >> a >> b; a--, b--;
    int g = tree.lca(a, b);
    int len = dep[a] + dep[b] - 2 * dep[g];
    if (pre[g] != dep[g] + 1) {
      int add = dep[g] + 1 - pre[g];
      int ans = base + len + 2 * add;
      cout << ans << '\n';
    }
    else {
      int qry = pre[a] + pre[b] - 2 * (g == rt ? 0 : pre[par[g]]);
      qry = max(0, qry - 2);
      int ans = base - 2 * qry + len;
      cout << ans << '\n';
    }
  }
}
