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
    int A, B, X; cin >> A >> B >> X;
    if (X == 0 || X == A) {
      cout << "YES" << '\n';
    }
    else if (X > A) {
      cout << "NO" << '\n';
    }
    else {
      cout << (X % gcd(A, B) == 0 ? "YES" : "NO") << '\n';
    }
  }();
}
