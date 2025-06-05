#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif
 
const int MN = 3001;
int lst[26][MN], dp[26][MN];
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, K; cin >> N >> K;
  memset(lst, 0x3f, sizeof(lst));
  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    memset(dp, 0x3f, sizeof(dp));
    string s; cin >> s;
    for (int j = 1; j <= N; ++j) {
      int c = s[j - 1] - 'A';
      dp[c][j] = 1;
      int need = 1;
      for (int k = 0; k < K; ++k) {
        dp[k][j] = min({dp[k][j - 1] + 1, lst[k][j] + 1, lst[k][j - 1] + 1, dp[k][j]});
        need = max(need, dp[k][j]);
      }
      if (need <= min(i, j)) {
        int add = min(i, j) - need + 1;
        ans += add;
      }
    }
    swap(lst, dp);
  }
  cout << ans << '\n';
}
