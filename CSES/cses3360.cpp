#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

using BS = bitset<(int)1e7>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, K; cin >> N >> K;
  vector<vector<int>> g(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c; cin >> c;
      g[i][j] = c - 'A';
    }
  }
  vector<BS> vis(K);
  vector<int> ans(K);
  for (int i = 0; i < N; ++i) {
    vector<vector<int>> idxs(K);
    for (int j = 0; j < N; ++j) {
      idxs[g[i][j]].push_back(j);
    }
    for (int c = 0; c < K; ++c) {
      if (ans[c]) continue;
      ans[c] = [&]() {
        int n = idxs[c].size();
        for (int a = 0; a < n; ++a) {
          for (int b = a + 1; b < n; ++b) {
            if (vis[c][idxs[c][a] * N + idxs[c][b]]) return 1;
            vis[c][idxs[c][a] * N + idxs[c][b]] = 1;
          }
        }
        return 0;
      }();
    }
  }
  for (int i = 0; i < K; ++i) {
    cout << (ans[i] ? "YES" : "NO") << '\n';
  }
}
