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
  int T;
  cin >> T;
  while (T--) [&]() {
    int N; cin >> N;
    vector<ll> ans(N), dp(N);
    for (int v = N - 1; v >= 0; --v) {
      ll a; int k; cin >> a >> k;
      dp[v] = 1;
      for (int i = 0; i < k; ++i) {
        int ch; cin >> ch; ch--;
        ans[v] += ans[ch];
        dp[v] = lcm(dp[v], gcd(dp[ch], a));
      }
      if (dp[v] == 1) {
        dp[v] = a;
        ans[v]++;
      }
      cout << ans[v] << '\n';
      cout.flush();
    }
  }();
}
