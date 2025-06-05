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
  int N; cin >> N;
  auto rev = [&](int i, int j) -> int {
    cout << i + 1 << " " << j + 1 << '\n';
    cout.flush();
    int inv; cin >> inv;
    return inv;
  };
  int inv = rev(0, N - 1);
  for (int i = 1; i < N; ++i) {
    rev(0, i);
    int nxt = rev(1, i);
    int delta = inv - nxt;
    int rank = i - (delta + i) / 2;
    if (rank) {
      rev(0, rank);
      inv = rev(0, rank - 1);
    }
    else inv = nxt;
  }
}
