#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int grid[8][8] = {
  {0, 3, 2, 3, 2, 3, 4, 5},
  {3, 4, 1, 2, 3, 4, 3, 4},
  {2, 1, 4, 3, 2, 3, 4, 5},
  {3, 2, 3, 2, 3, 4, 3, 4},
  {2, 3, 2, 3, 4, 3, 4, 5},
  {3, 4, 3, 4, 3, 4, 5, 4},
  {4, 3, 4, 3, 4, 5, 4, 5},
  {5, 4, 5, 4, 5, 4, 5, 6},
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) [&]() {
    int X, Y; cin >> X >> Y; X--, Y--;
    if (X < 8 && Y < 8) {
      cout << grid[X][Y] << '\n';
      return;
    }
    int moves = max({(X + Y + 2) / 3, (X + 1) / 2, (Y + 1) / 2});
    if ((X + Y) % 2 != moves % 2) moves++;
    cout << moves << '\n';    
  }();
}
