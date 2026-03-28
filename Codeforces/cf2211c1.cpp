#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct DisjointSet {
  vector<int> p;
  DisjointSet(int N) {
    p.resize(N);
    iota(p.begin(), p.end(), 0);
  }
  int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
  bool unite(int a, int b) {
    a = root(a), b = root(b);
    p[b] = a;
    return 1;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) [&]() {
    int N, K; cin >> N >> K;
    vector<int> a(N), b(N);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    auto upd = [&](int i, int x) -> bool {
      if (b[i] == -1) b[i] = x;
      return b[i] == x;
    };

    DisjointSet dsu(N);
    for (int i = K; i < N; ++i) {
      int j = i - K;
      if (a[j] == a[i]) {
        if (b[j] == -1 && b[i] == -1) {
          dsu.unite(i, j);
        }
        else if (b[j] == -1) {
          b[j] = b[i];
        }
        else if (b[i] == -1) {
          b[i] = b[j];
        }
        else {
          if (b[i] != b[j]) {
            cout << "NO" << '\n';
            return;
          }
        }
      }
      else {
        if (!upd(i, a[i]) || !upd(j, a[j])) {
          cout << "NO" << '\n';
          return;
        }
      }
    }

    map<int, int> init_cnts;
    for (int i = 0; i < K; ++i) {
      init_cnts[a[i]]++;
    }
    for (int i = 0; i < K; ++i) {
      int rep = dsu.root(i);
      if (b[rep] == -1) continue;
      init_cnts[b[rep]]--;
      if (init_cnts[b[rep]] < 0) {
        cout << "NO" << '\n';
        return;
      }
    }
    cout << "YES" << '\n';
  }();
}
