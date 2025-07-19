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
    ll N, M; cin >> N >> M;
    N--, M--;
    ll ans1 = 2 * lcm(N, M);
    ll g = 2 * gcd(N, M);
    ll cnt_mod_M_lo = (M % g == 0 ? M / g : M / g + 1) - 1;
    ll cnt_mod_M_hi = M / g;
    ll cnt_mod_N_lo = (N % g == 0 ? N / g : N / g + 1) - 1;
    ll cnt_mod_N_hi = N / g;
    ll sub = (cnt_mod_M_lo * cnt_mod_N_lo + cnt_mod_M_hi * cnt_mod_N_hi);
    ll ans2 = 1 + ans1 / 2 - sub;
    cout << ans1 << " " << ans2 << '\n';
  }();
}
