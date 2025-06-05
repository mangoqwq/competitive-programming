#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct RollbackUF {
	vector<int> e; vector<pair<int, int>> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return st.size(); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, M, Q; cin >> N >> M >> Q;
  struct Edge { int u, v, w; };
  vector<Edge> edges(M);
  map<int, vector<int>> edges_by_w;
  for (int i = 0; i < M; ++i) {
    auto &[u, v, w] = edges[i];
    cin >> u >> v >> w; u--, v--;
    edges_by_w[w].push_back(i);
  }

  vector<int> ans(Q, 1);
  struct Layer {
    vector<int> idxs; int qid;
  };
  map<int, vector<Layer>> q_layers;
  for (int i = 0; i < Q; ++i) {
    int k; cin >> k;
    map<int, vector<int>> layers;
    for (int j = 0; j < k; ++j) {
      int idx; cin >> idx; idx--;
      layers[edges[idx].w].push_back(idx);
    }
    for (auto [w, idxs] : layers) {
      q_layers[w].emplace_back(idxs, i);
    }
  }

  RollbackUF dsu(N);
  for (auto [w, e_ids] : edges_by_w) {
    for (auto [idxs, qid] : q_layers[w]) {
      int t = dsu.time();
      for (auto e_id : idxs) {
        auto [u, v, _] = edges[e_id];
        ans[qid] &= dsu.join(u, v);
      }
      dsu.rollback(t);
    }
    for (auto e_id : e_ids) {
      auto [u, v, _] = edges[e_id];
      dsu.join(u, v);
    }
  }
  
  for (int i = 0; i < Q; ++i) {
    cout << (ans[i] ? "YES" : "NO") << '\n';
  }
}
