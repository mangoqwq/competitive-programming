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
  int N, K; cin >> N >> K;
  vector<vector<int>> a(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    string s; cin >> s;
    for (int j = 0; j < N; ++j) {
      a[i][j] = s[j] - 'A';
    }
  }
  vector<ll> ans(K);
  for (int i1 = 0; i1 < N; ++i1) {
    vector<int> eq(N);
    for (int i2 = i1; i2 < N; ++i2) {
      for (int j = 0; j < N; ++j) {
        eq[j] += a[i2][j] == a[i1][j];
      }
      int lst = -1, cols = 0;
      for (int j = 0; j < N; ++j) {
        if (a[i1][j] != a[i2][j]) {
          lst = -1;
          cols = 0;
          continue;
        }
        if (a[i1][j] != lst) {
          lst = a[i1][j];
          cols = 0;
        }
        int complete = eq[j] == (i2 - i1 + 1);
        cols += complete;
        if (complete) {
          ans[lst] += cols;
        }
      }
    }
  }
  for (int i = 0; i < K; ++i) {
    cout << ans[i] << '\n';
  }
}
