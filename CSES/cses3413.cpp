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
  vector<vector<int>> a(N + 1, vector<int>(N + 1));
  vector<vector<int>> up(N + 1, vector<int>(N + 1));
  vector<vector<int>> lf(N + 1, vector<int>(N + 1));
  vector<vector<int>> sq(N + 1, vector<int>(N + 1));
  vector<ll> ans(K);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      char c; cin >> c; c -= 'A';
      a[i][j] = c;
      up[i][j] = up[i - 1][j] * (a[i][j] == a[i - 1][j]) + 1;
      lf[i][j] = lf[i][j - 1] * (a[i][j] == a[i][j - 1]) + 1;
      if (a[i][j] == a[i - 1][j - 1])
        sq[i][j] = min({sq[i - 1][j - 1] + 1, up[i][j], lf[i][j]});
      else sq[i][j] = 1;
      ans[c] += sq[i][j];
    }
  }
  for (int i = 0; i < K; ++i) {
    cout << ans[i] << '\n';
  }
}
