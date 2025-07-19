#include <bits/stdc++.h>
#include <queue>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct DisjointSet {
  vector<int> p, mx;
  DisjointSet(int N) {
    p.resize(N);
    mx.resize(N);
    iota(p.begin(), p.end(), 0);
    iota(mx.begin(), mx.end(), 0);
  }
  int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
  bool unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return 0;
    mx[a] = max(mx[a], mx[b]);
    p[b] = a;
    return 1;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N; cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<ll> b(N);
  for (int i = 1; i < N; ++i) {
    b[i] = a[i] - a[i - 1];
  }
  debug(b);

  vector<ll> psa(N + 2);
  for (int i = 1; i < N; ++i) {
    psa[i + 2] = b[i];
    if (i) psa[i + 2] += psa[i];
  }
  auto get = [&](int l, int r) { // [l, r]
    return psa[r + 2] - psa[l];
  };

  struct Item {
    int l, r; ll cost;
    bool operator<(const Item &other) const {
      return cost > other.cost;
    }
  };
  priority_queue<Item> pq;
  for (int i = 1; i < N; ++i) {
    pq.emplace(i, i, get(i, i));
  }
  DisjointSet dsu(N + 1);
  
  ll ans = 0;
  for (int k = 1; k <= N / 2; ++k) {
    while (true) {
      auto [l, r, cost] = pq.top(); pq.pop();
      if (dsu.root(l) != l) continue;
      if (dsu.mx[l] != r) continue;
      ans += cost;
      int nl = dsu.root(l - 1);
      while (dsu.mx[nl] < r + 1) {
        dsu.unite(nl, dsu.mx[nl] + 2);
      }
      int nr = dsu.mx[nl];
      if (nl >= 1 && nr <= N - 1) {
        pq.emplace(nl, nr, get(nl, nr) - get(nl + 1, nr - 1));
      }
      break;
    }
    cout << ans << (k == N / 2 ? '\n' : ' ');
  }
}
