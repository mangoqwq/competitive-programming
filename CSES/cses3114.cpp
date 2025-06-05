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
  vector<vector<int>> mn;
  vector<int> in, out, dep;
  const int e = 1e9;
  LCA (vector<vector<int>> adj, vector<int> val, int rt) 
    : N(adj.size()), L(__lg(N)+1), up(N, vector<int>(L)), mn(N, vector<int>(L, e)), in(N), out(N), dep(N) {
    int T = 0;
    auto dfs = [&](auto self, int v, int p) -> void {
      in[v] = ++T; up[v][0] = p;
      mn[v][0] = val[v];
      for (int i = 1; i < L; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        mn[v][i] = min(mn[v][i-1], mn[up[v][i-1]][i-1]);
      }
      for (auto to : adj[v]) {
        if (to == p) continue;
        dep[to] = dep[v] + 1;
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
  int qry(int a, int b) {
    int g = lca(a, b);
    int ret = mn[g][0];
    for (int i = L-1; i >= 0; --i) {
      if (!is_anc(up[a][i], g)) {
        ret = min(ret, mn[a][i]);
        a = up[a][i];
      }
      if (!is_anc(up[b][i], g)) {
        ret = min(ret, mn[b][i]);
        b = up[b][i];
      }
    }
    if (a != g) ret = min(ret, mn[a][0]);
    if (b != g) ret = min(ret, mn[b][0]);
    return ret;
  }
  int dist(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, Q; cin >> N >> Q;
  vector<int> dist(N, 1e9);
  queue<int> q;
  for (int i = 0; i < N; ++i) {
    int x; cin >> x;
    if (x) {
      dist[i] = 0;
      q.push(i);
    }
  }

  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b; cin >> a >> b; a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int to : adj[v]) {
      if (dist[to] > dist[v] + 1) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }
  debug(dist);
  
  LCA tree(adj, dist, 0);
  while (Q--) {
    int a, b; cin >> a >> b; a--, b--;
    int ans = tree.dist(a, b) + 2 * tree.qry(a, b);
    debug(tree.dist(a, b), tree.qry(a, b));
    cout << ans << '\n';
  }
}
