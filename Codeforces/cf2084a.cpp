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
    int N; cin >> N;
    if (N % 2 == 0) {
      cout << -1 << '\n';
    }
    else {
      cout << N << ' ';
      for (int i = 1; i < N; ++i) {
        cout << i << (i == N-1 ? '\n' : ' ');
      }
    }
  }();
}
