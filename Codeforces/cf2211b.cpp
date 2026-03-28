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
  int T; cin >> T;
  while (T--) [&]() {
    int x, y; cin >> x >> y;
    int tot = x - y;
    int ans = 0;
    for (int i = 1; i <= abs(tot); ++i) {
      if (tot % i == 0) ans++;
    }
    if (tot == 0) ans = 1;
    cout << ans << '\n';
    for (int i = 0; i < (x + y); ++i) {
      cout << (i < x ? 1 : -1) << (i == x + y - 1 ? '\n' : ' ');
    }
  }();
}
