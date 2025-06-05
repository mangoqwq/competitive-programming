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
  int N, M; cin >> N >> M;
  vector<pair<int, int>> edges;
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b; a--, b--;
    edges.emplace_back(a, b);
  }

  vector<int> indep(1 << N);
  for (int msk = 0; msk < (1 << N); ++msk) {
    bool valid = 1;
    for (auto [a, b] : edges) {
      if ((1 & (msk >> a)) && (1 & (msk >> b))) valid = 0;
    }
    indep[msk] = valid;
  }

  vector<int> dp(1 << N, 1e9), from(1 << N);
  dp[0] = 0;
  for (int msk = 0; msk < (1 << N); ++msk) {
    for (int add = msk; add; add = (add - 1) & msk) {
      if (!indep[add]) continue;
      if (indep[add] && dp[msk] > dp[msk - add] + 1) {
        dp[msk] = dp[msk - add] + 1;
        from[msk] = add;
      }
    }
  }
  vector<int> color(N);
  int msk = (1 << N) - 1;
  int T = 0;
  while (msk) {
    for (int i = 0; i < N; ++i) {
      if (1 & (from[msk] >> i)) color[i] = T;
    }
    msk -= from[msk];
    T++;
  }
  cout << dp.back() << '\n';
  for (int i = 0; i < N; ++i) {
    cout << color[i] + 1 << (i == N - 1 ? '\n' : ' ');
  }
}
