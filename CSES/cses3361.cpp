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
  vector<int> a(2 * N);
  for (int i = 0; i < 2 * N; ++i) {
    cin >> a[i];
  }
  reverse(a.begin(), a.begin() + N);
  // l < N, r > N
  double lo = 0, hi = 1e10;
  int arg_l, arg_r;
  for (int it = 0; it < 100; ++it) {
    double mi = (lo + hi) / 2;
    vector<double> psa(2 * N + 1);
    for (int i = 0; i < 2 * N; ++i) {
      psa[i + 1] = psa[i] + a[i] - mi;
    }
    auto l = min_element(psa.begin(), psa.begin() + N);
    auto r = max_element(psa.begin() + N + 1, psa.end());
    if (*r - *l >= 0) {
      lo = mi;
      arg_l = psa.begin() + N - l;
      arg_r = r - (psa.begin() + N);
    }
    else hi = mi;
  }
  cout << arg_l << " " << arg_r << '\n';
}
