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
  int N; cin >> N;
  if (N <= 3) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  vector<vector<int>> ans(N, vector<int>(N));
  for (int i = 0; i < N-1; ++i) {
    fill(ans[i].begin(), ans[i].end() - 1, i + 1);
    ans[N - 1][i] = i + 1;
  }
  for (int i = 0; i < N; ++i) {
    ans[i][N - 1] = N;
  }
  if (N % 2 == 0) {
    swap(ans[N - 1][N - 2], ans[N/2 - 2][N - 1]);
    swap(ans[N - 1][N/2 - 2], ans[N/2 - 1][N/2 - 2]);
  }
  else {
    swap(ans[N - 1][1], ans[N/2 - 1][N - 1]);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << ans[i][j] << (j == N - 1 ? '\n' : ' ');
    }
  }
}
