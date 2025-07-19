#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

constexpr int MN = 500 * 1000;
using bs = bitset<MN + 1>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N; cin >> N;
  vector<bs> dp(N + 1);
  dp[0][0] = 1;
  int tot = 0;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    dp[i + 1] = dp[i] | (dp[i] << a[i]);
    tot += a[i];
  }
  if (tot % 2 == 1 || !dp[N][tot / 2]) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> neg, pos;
  int cur = tot / 2;
  for (int i = N - 1; i >= 0; --i) {
    if (!dp[i][cur]) pos.push_back(a[i]), cur -= a[i];
    else neg.push_back(a[i]);
  }
  for (int i = 0; i < N - 1; ++i) {
    int x = pos.back(); pos.pop_back();
    int y;
    if (neg.empty()) y = pos.back(), pos.pop_back();
    else y = neg.back(); neg.pop_back();
    cout << x << " " << y << '\n';
    if (x > y) pos.push_back(x - y);
    else neg.push_back(y - x);
  }
}
