#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct DominatorTree {
  int V, ind; vector<int> idom, sdom, par, ord, U, UF, m;
  vector<vector<int>> bucket, H;
  int find(int v) {
    if (UF[v] == v) return v;
    int fv = find(UF[v]);
    if (sdom[m[v]] > sdom[m[UF[v]]]) m[v] = m[UF[v]];
    return UF[v] = fv;
  }
  int eval(int v) { find(v); return m[v]; }
  template <class Digraph> void dfs(const Digraph &G, int v) {
    ord[sdom[v] = ind++] = v; for (int w : G[v])
      if (sdom[w] == -1) { par[w] = v; dfs(G, w); }
  }
  template <class Digraph>
  DominatorTree(const Digraph &G, int root)
      : V(G.size()), ind(0), idom(V, -1), sdom(V, -1),
        par(V, -1), ord(V, -1), U(V, -1), UF(V), m(V),
        bucket(V), H(V) {
    for (int v = 0; v < V; v++) {
      UF[v] = m[v] = v; for (int w : G[v]) H[w].push_back(v);
    }
    dfs(G, root); for (int i = ind - 1; i > 0; i--) {
      int w = ord[i]; for (int v : H[w]) if (sdom[v] >= 0)
        sdom[w] = min(sdom[w], sdom[eval(v)]);
      bucket[ord[sdom[w]]].push_back(w);
      for (int v : bucket[par[w]]) U[v] = eval(v);
      bucket[UF[w] = par[w]].clear();
    }
    for (int i = 1; i < ind; i++) {
      int w = ord[i], u = U[w];
      idom[w] = sdom[w] == sdom[u] ? sdom[w] : idom[u];
    }
    for (int i = 1; i < ind; i++) {
      int w = ord[i]; idom[w] = ord[idom[w]];
    }
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, M; cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b; a--, b--;
    adj[a].push_back(b);
  }
  DominatorTree dt(adj, 0);
  vector<int> ans;
  ans.push_back(N - 1);
  while (ans.back() != 0) {
    ans.push_back(dt.idom[ans.back()]);
  }
  ranges::sort(ans);
  cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] + 1 << (i == (int)ans.size() - 1 ? '\n' : ' ');
  }
}
