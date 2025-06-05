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
  vector<vector<int>> up(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    struct Item { int l, h; };
    vector<Item> stk;
    int last_c = -1;
    auto push = [&](int r, int nh) {
      int nl = r;
      while (!stk.empty() && stk.back().h >= nh) {
        auto [l, h] = stk.back(); stk.pop_back();
        nl = l;
        int lh = max(nh, (stk.empty() ? 0 : stk.back().h));
        ll w = r - l;
        ans[last_c] += w * (w + 1) * (h - lh) / 2;
      }
      if (nh) stk.emplace_back(nl, nh);
    };
    for (int j = 0; j < N; ++j) {
      if (!i) up[i][j] = 1;
      else up[i][j] = up[i - 1][j] * (a[i][j] == a[i - 1][j]) + 1;
      if (a[i][j] != last_c) {
        push(j, 0);
      }
      last_c = a[i][j];
      push(j, up[i][j]);
      debug(stk);
    }
    push(N, 0);
    debug(ans);
  }
  for (int i = 0; i < K; ++i) {
    cout << ans[i] << '\n';
  }
}
