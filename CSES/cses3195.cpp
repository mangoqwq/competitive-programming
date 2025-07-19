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
  vector<int> a(N);
  for (int &x : a) cin >> x;
  for (int b = 0; b < 20; ++b) {
    if (!(1 & (N - K) >> b)) continue;
    N -= (1 << b);
    for (int i = 0; i < N; ++i) a[i] ^= a[i + (1 << b)];
  }
  for (int i = 0; i < N; ++i) {
    cout << a[i] << (i == N - 1 ? '\n' : ' ');
  }
}
