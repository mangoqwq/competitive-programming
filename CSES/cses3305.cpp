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
  auto ask = [&](char c, int i) -> int {
    cout << c << " " << i << '\n';
    cout.flush();
    int x; cin >> x;
    return x;
  };
  if (K <= N && ask('F', K) > ask('S', 1)) {
    int ans = ask('F', K);
    cout << "! " << ans << '\n';
    return 0;
  }
  if (K <= N && ask('S', K) > ask('F', 1)) {
    int ans = ask('S', K);
    cout << "! " << ans << '\n';
    return 0;
  }
  int lo = max(1, K - N), hi = min(N, K - 1);
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    int a = ask('F', mi + 1), b = ask('S', K - mi);
    if (a > b) lo = mi + 1;
    else hi = mi;
  }
  int ans = min(ask('F', lo), ask('S', K - lo));
  cout << "! " << ans << '\n';
}
