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
    int X, Y, Z; cin >> X >> Y >> Z;
    // 1 0 1 2 1 0 1 1 0 1 2
    if (Z > X) {
      cout << "No" << '\n';
      return;
    }
    if (Y > 2 * X) {
      cout << "No" << '\n';
      return;
    }
    // 0 2 0 2 0 1 1 0 1 2
    if (Z == 0 && Y % 2 == 1) {
      cout << "No" << '\n';
      return;
    }
    cout << "Yes" << '\n';
  }();
}

